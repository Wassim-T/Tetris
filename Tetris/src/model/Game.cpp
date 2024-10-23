#include "Game.h"

namespace model {

    Game::Game(Grid &grid, std::string &name, BagBrick &bag, int level) : _level(level), _speed(1), _bag(bag),
                                                                          _grid(grid),
                                                                          _player(name), _totalLines(0) {
        _curr_brick = _bag.getNextBrick();
        _next_brick = _bag.getNextBrick();


        _grid.spawnBrick(_curr_brick);
    }

    void Game::nextShape() {
        if (hasWon()){
            //eventually store in a DB the player so we can add a leaderboard system
            notifyObservers(Notification::WIN);
            exit(0);
        }

            _curr_brick = _next_brick;
            _next_brick = _bag.getNextBrick();
            if (!_grid.spawnBrick(_curr_brick)) {
                gameOver();
            }
            notifyObservers(Notification::NEW_BRICK);
            notifyObservers(Notification::NEW_SHADOW);


    }

    void Game::setScore() {
        int lines = _grid.getNbLines();
        _totalLines += lines;
        if (_totalLines % 10 == 0) {
            nextLevel();
        }
        _player.setScore(lines, _grid.getHDrop(), _level);
        notifyObservers(Notification::NEW_SCORE);
    }

    void Game::moveBrick() {

        if (!_grid.moveBrick(_curr_brick, DirectionStruct::DOWN)) {
            playSound();
        }


        if (_grid.isBrickPlaced(_curr_brick)) {
            if (_grid.checkLine(_curr_brick)) {
                setScore();
            }
            nextShape();
        }

        notifyObservers(Notification::NEW_BRICK);
        notifyObservers(Notification::NEW_POSITION);

    }


    void Game::moveBrick(const DIRECTION2D &dir) {

        if (!_grid.moveBrick(_curr_brick, dir)) {
            playSound();
        }

        if (_grid.isBrickPlaced(_curr_brick)) {
            if (_grid.checkLine(_curr_brick)) {
                setScore();
            }
            nextShape();
        }

        notifyObservers(Notification::NEW_SHADOW);
        notifyObservers(Notification::NEW_BRICK);
        notifyObservers(Notification::NEW_POSITION);

    }


    void Game::rotateBrick(const DIRECTION2D &dir) {


        if (!_grid.rotateBrick(_curr_brick, dir)) {
            playSound();
        }
        notifyObservers(Notification::NEW_SHADOW);
        notifyObservers(Notification::NEW_BRICK);
        notifyObservers(Notification::NEW_POSITION);


    }

    void Game::computeSpeed() {
        auto it = LEVEL_SPEED.find(_level);
        _speed = it->second;
    }

    void Game::nextLevel() {
        if (_level < MAX_LEVEL) {
            _level++;
            computeSpeed();
            notifyObservers(Notification::NEW_LEVEL);
        }
    }

    void Game::playSound() {
        notifyObservers(Notification::NEW_SOUND);
    }

    void Game::gameOver() {
        //eventually store in a DB the player so we can add a leaderboard system

        notifyObservers(Notification::GAME_OVER);

        exit(0);

    }

    int Game::getScore() const {
        return _player.getScore();
    }

    GRID2D &Game::getGrid() {
        return _grid.getGrid();
    }

    std::string Game::getPlayerName() const {
        return _player.getName();
    }

    Brick Game::getCurrentBrick() {
        return _curr_brick;
    }

    Brick Game::getNextBrick() {
        return _next_brick;
    }

    Brick Game::getShadow() {
        return _grid.getShadow();
    }


    void model::Game::addObserver(std::shared_ptr<Observer> observer) {
        if (std::find_if(_observers.begin(), _observers.end(),
                         [&](const std::weak_ptr<Observer> &o) { return o.lock().get() == observer.get(); }) ==
            _observers.end()) {
            _observers.push_back(observer);
        }
    }

    void model::Game::removeObserver(std::shared_ptr<Observer> observer) {
        _observers.erase(std::remove_if(_observers.begin(), _observers.end(),
                                        [&](const std::weak_ptr<Observer> &o) {
                                            return o.lock().get() == observer.get();
                                        }),
                         _observers.end());
    }

    void Game::notifyObservers(Notification notification) {
        for (const auto &obs: _observers) {

            obs.lock()->update(notification);
        }
    }

    int Game::getLevel() const {
        return _level;
    }

    double Game::getSpeed() const {
        return _speed;
    }

    bool Game::hasWon() {
        if (_totalLines == 210) { //210 because 200 lines are required to go to level 20 (20*10), so you must beat level 20 to win
            return true;
        }
        if (_player.getScore() == 10000) {
            return true;
        }
        //TODO the user win if a certain amount of time has elapsed from the start of the game (in graphic view)
        return false;
    }


    void Game::dropBrick(){
        _grid.dropBrick(_curr_brick);
        if (_grid.isBrickPlaced(_curr_brick)) {
            if (_grid.checkLine(_curr_brick)) {
                setScore();
            }
            nextShape();
        }

        notifyObservers(Notification::NEW_BRICK);
        notifyObservers(Notification::NEW_POSITION);
    }

    void Game::setName(std::string name){
        _player.setName(name);
    }
}

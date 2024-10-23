#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <map>
#include "Brick.h"
#include "Player.h"
#include "Grid.h"
#include "BagBrick.h"
#include "util/Observable.hpp"


namespace model {
    class Game : public Observable {
        Brick _curr_brick;
        Brick _next_brick;
        double _speed;
        int _level;
        static const int MAX_LEVEL = 20;
        int _totalLines;
        Player _player;
        Grid _grid;
        BagBrick _bag;
        std::vector<std::weak_ptr<Observer>> _observers;
         const std::map<int, double> LEVEL_SPEED ={
                {1,60/60}, {2,53/60}, {3,49/60}, {4,45/60}, {5,41/60}, {6,37/60},
                {7,33/60}, {8,28/60}, {9,23/60}, {10, 18/60}, {11, 13/60}, {12, 8/60},
                {13,9/60}, {14, 8/60}, {15, 7/60}, {16, 6/60}, {17, 5/60}, {18, 4/60},
                {19, 3/60}

        };


    public:
         /**
         * @brief Constructor to initialize the game.
         *
         * @param grid Reference to the game grid.
         * @param name The name of the player.
         * @param bag Reference to the bag of bricks.
         * @param level The initial level of the game.
         */
         Game(Grid &grid, std::string &name, BagBrick &bag, int level);

         /**
         * @brief Moves the current active brick down.
         *
         * If the brick cannot move further down, it checks for line completion,
         * sets the score, and spawns the next brick.
         */
         void moveBrick();

         /**
         * @brief Moves the current active brick in the specified direction.
         *
         * @param dir The direction in which to move the brick.
         *
         * If the brick cannot move further in the specified direction, it checks
         * for line completion, sets the score, and spawns the next brick.
         */
         void moveBrick(const DIRECTION2D &dir);

         /**
         * @brief Rotates the current active brick in the specified direction.
         *
         * @param dir The direction in which to rotate the brick.
         *
         * If the brick cannot rotate in the specified direction, it plays a sound.
         */
         void rotateBrick(const DIRECTION2D &dir);

         /**
         * @brief Gets the current score of the player.
         *
         * @return The current score.
         */
         int getScore() const;

         /**
         * @brief Gets the game grid.
         *
         * @return Reference to the game grid.
         */
         GRID2D &getGrid();

         /**
         * @brief Gets the name of the player.
         *
         * @return The name of the player.
         */
         std::string getPlayerName() const;

         /**
         * @brief Gets the current active brick.
         *
         * @return The current active brick.
         */
         Brick getCurrentBrick();

         /**
         * @brief Gets the next upcoming brick.
         *
         * @return The next upcoming brick.
         */
         Brick getNextBrick();

         /**
         * @brief Gets the shadow of the current active brick.
         *
         * The shadow represents the projected position of the current active brick
         * if it were to be dropped instantly.
         *
         * @return The shadow of the current active brick.
         */
         Brick getShadow();

         /**
         * @brief Gets the current level of the game.
         *
         * @return The current level.
         */
         int getLevel() const;

         /**
         * @brief Gets the speed of the game.
         *
         * @return The speed of the game.
         */
         double getSpeed() const;

         /**
         * @brief Adds an observer to the game.
         *
         * @param observer The observer to be added.
         */
         void addObserver(std::shared_ptr<Observer> observer) override;

         /**
         * @brief Removes an observer from the game.
         *
         * @param observer The observer to be removed.
         */
         void removeObserver(std::shared_ptr<Observer> observer) override;

         /**
         * @brief Notifies all observers about a specific game event.
         *
         * @param notification The notification to be sent to observers.
         */
         void notifyObservers(Notification notification) override;

         /**
         * @brief Drops the current active brick instantly to the bottom.
         *
         * If the brick cannot be dropped further, it checks for line completion,
         * sets the score, and spawns the next brick.
         */
         void dropBrick();

         /**
          * @brief setName set player name.
          */
         void setName(std::string name);

     private:
         /**
         * @brief Plays a sound effect.
         *
         * This method is called when the current active brick cannot be moved
         * further down or rotated.
         */
         void playSound();

         /**
         * @brief Handles the game over scenario.
         *
         * This method is called when the game is over, i.e., when the current
         * active brick cannot be spawned on the grid.
         */
         void gameOver();

         /**
         * @brief Spawns the next shape on the grid.
         *
         * If the game is won (all levels completed), it notifies observers
         * and exits the game.
         *
         * If the game is not won, it sets the current brick to the next brick
         * in the bag and spawns it on the grid. If the grid is unable to spawn
         * the brick, it triggers the game over scenario.
         */
         void nextShape();

         /**
         * @brief Sets the player's score based on line completion and drop height.
         *
         * If a line is completed by the current active brick, it increments the
         * score and total lines. If the total lines reach a multiple of 10, it
         * triggers the next level.
         */
         void setScore();

         /**
         * @brief Checks if the player has won the game.
         *
         * The player wins if either 200 lines are completed (reaching level 20)
         * or the score reaches 10,000.
         *
         * @return True if the player has won, false otherwise.
         */
         bool hasWon();

         /**
         * @brief Computes the game speed based on the current level.
         *
         * The game speed increases as the level increases.
         */
         void computeSpeed();

         /**
         * @brief Advances the game to the next level.
         *
         * If the current level is less than the maximum level (20), it increments
         * the level, computes the new speed, and notifies observers about the
         * level change.
         */
         void nextLevel();

    };
}


#endif //TETRIS_GAME_H

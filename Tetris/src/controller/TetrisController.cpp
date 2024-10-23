/**
 * @file TetrisController.cpp
 * @brief Implements the TetrisController class methods.
 */

#include "TetrisController.h"

namespace controller {

TetrisController::TetrisController(std::shared_ptr<model::Game> &game) : _facade(game) {}

model::GRID2D &TetrisController::getGrid() {
    return _facade->getGrid();
}

int TetrisController::getScore() const {
    return _facade->getScore();
}

void TetrisController::moveBrick(const model::DIRECTION2D &dir) {
    _facade->moveBrick(dir);
}

std::string TetrisController::getPlayerName() const {
    return _facade->getPlayerName();
}

void TetrisController::moveBrick() {
    _facade->moveBrick();
}

void TetrisController::rotateBrick(const model::DIRECTION2D &dir) {
    _facade->rotateBrick(dir);
}

model::Brick TetrisController::getCurrentBrick() const {
    return _facade->getCurrentBrick();
}

model::Brick TetrisController::getNextBrick() const {
    return _facade->getNextBrick();
}

model::Brick TetrisController::getShadow() const {
    return _facade->getShadow();
}

int TetrisController::getLevel() const {
    return _facade->getLevel();
}

int TetrisController::getSpeed() const {
    return _facade->getSpeed();
}

void TetrisController::addObserver(std::shared_ptr<model::Observer> observer) {
    _facade->addObserver(observer);
}

void TetrisController::dropBrick() {
    _facade->dropBrick();
}
void TetrisController::setUsername(std::string name){
    _facade->setName(name);
}

}

/**
 * @file BagBrick.cpp
 * @brief Implementation of the BagBrick class.
 */

#include "BagBrick.h"

namespace model {

BagBrick::BagBrick(const std::array<Brick, 7> &bricks) : _bag(bricks) {
    _nextBrickPos = 0;
}

Brick BagBrick::getNextBrick() {

    if (_nextBrickPos == 0) {
        shuffle();
    }

    Brick brick = _bag.at(_nextBrickPos);

    _nextBrickPos = (_nextBrickPos + 1) % SIZE;

    return brick;
}

void BagBrick::shuffle() {

    std::shuffle(_bag.begin(), _bag.end(), nvs::urng()); // Shuffle the bag using random number generator
}
}

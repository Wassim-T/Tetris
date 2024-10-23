/**
 * @file BagBrick.h
 * @brief Defines the BagBrick class.
 */

#ifndef TETRIS_BAGBRICK_H
#define TETRIS_BAGBRICK_H

#include "Brick.h"
#include <array>
#include <algorithm>
#include <random>
#include "util/random.hpp"

namespace model {

/**
     * @class BagBrick
     * @brief Manages a bag of bricks for Tetris game.
     */
class BagBrick {
    static constexpr int SIZE = 7; ///< Size of the bag
    std::array<Brick, SIZE> _bag; ///< Array holding bricks in the bag
    short _nextBrickPos; ///< Position of the next brick in the bag

public:
    /**
         * @brief Constructor.
         * @param bricks Array of bricks to initialize the bag.
         */
    BagBrick(const std::array<Brick, 7> &bricks);

    /**
         * @brief Default constructor.
         */
    BagBrick() = default;

    /**
         * @brief Gets the next brick from the bag.
         * @return The next brick from the bag.
         */
    Brick getNextBrick();

private:
    /**
         * @brief Shuffles the bricks in the bag.
         */
    void shuffle();
};
}

#endif //TETRIS_BAGBRICK_H

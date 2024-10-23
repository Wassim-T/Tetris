/**
 * @file BrickFactory.h
 * @brief Declares the BrickFactory class responsible for creating Tetris bricks.
 */

#ifndef TETRIS_BRICKFACTORY_H
#define TETRIS_BRICKFACTORY_H

#include "TypeBrick.hpp"
#include "Brick.h"
#include "util/random.hpp"

namespace model {
/**
     * @class BrickFactory
     * @brief Creates Tetris bricks.
     */
class BrickFactory {
    int _widthInitialPos; ///< Initial position of the bricks on the grid.

public:
    /**
         * @brief Constructor.
         * @param gridWidth Width of the grid.
         */
    BrickFactory(int gridWidth);

    /**
         * @brief Creates a Tetris brick based on the provided brick type.
         * @param typeBrick Type of the brick to create.
         * @return Created Tetris brick.
         */
    Brick makeBrick(const TypeBrick& typeBrick);
};
}

#endif //TETRIS_BRICKFACTORY_H

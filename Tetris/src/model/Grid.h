#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#include <vector>
#include <memory>
#include "Box.h"
#include "Brick.h"
#include <set>
#include "util/random.hpp"

namespace model {

using GRID2D = std::vector<std::vector<std::shared_ptr<Box>>>;

/**
     * @brief The class representing the grid of the Tetris game.
     *
     * The grid holds information about the positions of the boxes
     * and bricks in the game. It also handles operations related
     * to bricks movement, rotation, line clearing, and shadow
     * generation.
     */
class Grid {
    GRID2D _grid; /**< 2D vector representing the grid */
    Brick _shadow; /**< Shadow of the current active brick */
    int _nbLines; /**< Number of lines cleared */
    int _hDrop; /**< Height of the brick drop */

public:
    /**
         * @brief Constructs a grid with specified dimensions and grid density.
         *
         * @param height The height of the grid.
         * @param width The width of the grid.
         * @param gridDensity The density of occupied cells in the grid.
         */
    Grid(int height, int width, int gridDensity);

    /**
         * @brief Default constructor.
         */
    Grid() = default;

    /**
         * @brief Checks and clears completed lines on the grid.
         *
         * If any line is completed by the current active brick,
         * it clears those lines from the grid and updates the
         * score.
         *
         * @param currBrick The current active brick.
         * @return True if lines were cleared, false otherwise.
         */
    bool checkLine(Brick &currBrick);

    /**
         * @brief Gets the number of lines cleared.
         *
         * @return The number of lines cleared.
         */
    int getNbLines();

    /**
         * @brief Checks if the given brick is placed on the grid.
         *
         * If the given brick is the same as the shadow, it fills
         * the grid with the color of the brick.
         *
         * @param currBrick The current active brick.
         * @return True if the brick is placed, false otherwise.
         */
    bool isBrickPlaced(Brick &currBrick);

    /**
         * @brief Gets the height of the brick drop.
         *
         * @return The height of the brick drop.
         */
    int getHDrop();

    /**
         * @brief Moves the current active brick in the specified direction.
         *
         * @param currBrick The current active brick.
         * @param dir The direction to move the brick.
         * @return True if the move is valid, false otherwise.
         */
    bool moveBrick(Brick &currBrick, const DIRECTION2D &dir);

    /**
         * @brief Rotates the current active brick in the specified direction.
         *
         * @param currBrick The current active brick.
         * @param dir The direction to rotate the brick.
         * @return True if the rotation is valid, false otherwise.
         */
    bool rotateBrick(Brick &currBrick, const DIRECTION2D &dir);

    /**
         * @brief Spawns the current active brick on the grid.
         *
         * @param currBrick The current active brick.
         * @return True if the brick can be spawned, false otherwise.
         */
    bool spawnBrick(Brick &currBrick);

    /**
         * @brief Gets a reference to the grid.
         *
         * @return A reference to the grid.
         */
    GRID2D &getGrid();

    /**
         * @brief Gets the shadow of the current active brick.
         *
         * @return The shadow of the current active brick.
         */
    Brick getShadow();

    /**
         * @brief Drops the current active brick.
         *
         * Drops the current active brick to its shadow position.
         *
         * @param currBrick The current active brick.
         */
    void dropBrick(Brick &currBrick);

private:
    /**
         * @brief Finds the maximum line number from a set of positions.
         *
         * @param positions A set of positions to find the maximum line from.
         * @return The maximum line number.
         */
    int maxLine(const std::set<int> &positions);

    /**
         * @brief Checks if a line is completed.
         *
         * @param row The row number representing the line.
         * @return True if the line is completed, false otherwise.
         */
    bool isLine(int row);

    /**
         * @brief Moves a line down by one position.
         *
         * @param row The row number representing the line.
         */
    void moveLineDown(int row);

    /**
         * @brief Removes a completed line from the grid.
         *
         * @param row The row number representing the line to remove.
         */
    void removeLine(int row);

    /**
         * @brief Checks if a line is empty.
         *
         * @param row The row number representing the line.
         * @return True if the line is empty, false otherwise.
         */
    bool isLineEmpty(int row);

    /**
         * @brief Checks if a move is valid.
         *
         * @param pos The position to move.
         * @param dir The direction to move.
         * @param height The height of the grid.
         * @param width The width of the grid.
         * @return True if the move is valid, false otherwise.
         */
    bool isValidMove(Position &pos, const DIRECTION2D &dir, int height, int width);

    /**
         * @brief Checks if a move is valid.
         *
         * @param pos The position to move.
         * @param dir The direction to move.
         * @param height The height of the grid.
         * @param width The width of the grid.
         * @return True if the move is valid, false otherwise.
         */
    bool isValidMove(Position &&pos, const DIRECTION2D &dir, int height, int width);

    /**
         * @brief Sets the shadow of the current active brick.
         *
         * @param currBrick The current active brick.
         */
    void setShadow(Brick &currBrick);

    /**
         * @brief Checks if a position is out of bounds.
         *
         * @param pos The position to check.
         * @return True if the position is out of bounds, false otherwise.
         */
    bool checkOutOfBounds(Position &pos);

    /**
         * @brief Gets the highest position from a vector of positions.
         *
         * @param positions A vector of positions.
         * @return The highest position.
         */
    int getHighestPos(std::vector<int> &positions);
};

}

#endif //TETRIS_GRID_H

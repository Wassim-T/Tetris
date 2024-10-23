/**
 * @file Box.h
 * @brief Declares the Box class representing a box in the Tetris grid.
 */

#ifndef TETRIS_BOX_H
#define TETRIS_BOX_H

#include "Position.h"
#include "Brick.h"
#include <memory>
#include <optional>
#include "util/TetrisException.h"

namespace model {

/**
     * @class Box
     * @brief Represents a box in the Tetris grid.
     */
class Box {
    std::optional<Color> _color; ///< Optional color of the box

public:

    /**
         * @brief Default constructor.
         */
    Box() = default;

    /**
         * @brief Gets the color of the box.
         * @return Color of the box.
         * @throw TetrisException If the box has no color value.
         */
    Color getColor();

    /**
         * @brief Sets the color of the box.
         * @param color Color to set.
         */
    void setColor(const Color &color);

    /**
         * @brief Empties the box (removes color).
         */
    void emptyBox();

    /**
         * @brief Checks if the box is occupied (has color).
         * @return True if the box is occupied, false otherwise.
         */
    bool isOccuped();
};
}

#endif //TETRIS_BOX_H

#ifndef TETRIS_SQUARE_H
#define TETRIS_SQUARE_H

#include "Position.h"

namespace model {

/**
     * @brief Represents a square in the Tetris game grid.
     *
     * The Square class represents a square block in the Tetris game grid.
     * It holds the position of the square.
     */
class Square {
    Position _pos; /**< The position of the square in the grid */

public:

    /**
         * @brief Constructs a Square object with the specified position.
         *
         * @param pos The position of the square.
         */
    Square(Position& pos);

    /**
         * @brief Constructs a Square object by moving the specified position.
         *
         * @param pos The position of the square to move.
         */
    Square(Position&& pos);

    /**
         * @brief Gets the position of the square.
         *
         * @return The position of the square.
         */
    Position getPos() const;

    /**
         * @brief Allows modification of the position of the square.
         *
         * @return A reference to the position of the square, allowing modification.
         */
    Position& modifyPos();

    /**
         * @brief Overloaded equality operator.
         *
         * @param other The other Square object to compare.
         * @return True if both squares have the same position, false otherwise.
         */
    bool operator == (const Square &other) const;
};
}

#endif // TETRIS_SQUARE_H

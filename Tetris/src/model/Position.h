#ifndef TETRIS_POSITION_H
#define TETRIS_POSITION_H

#include "Direction.hpp"
#include <iostream>

namespace model {

/**
     * @brief Represents a 2D position.
     *
     * The Position class represents a 2D position using integer coordinates.
     */
class Position {
    std::pair<int, int> _pos; /**< The coordinates of the position */

public:
    /**
         * @brief Constructs a Position object with the specified coordinates.
         *
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         */
    Position(int x = 0, int y = 0);

    /**
         * @brief Gets the x-coordinate of the position.
         *
         * @return The x-coordinate of the position.
         */
    int get_x() const;

    /**
         * @brief Gets the y-coordinate of the position.
         *
         * @return The y-coordinate of the position.
         */
    int get_y() const;

    /**
         * @brief Overloaded equality operator.
         *
         * @param rhs The other Position object to compare.
         * @return True if both positions have the same coordinates, false otherwise.
         */
    bool operator==(const Position& rhs) const;

    /**
         * @brief Overloaded addition operator.
         *
         * Adds the components of the given direction to the current position.
         *
         * @param d The direction to add.
         * @return The resulting position after addition.
         */
    Position operator+(const DIRECTION2D &d);
};

}

#endif //TETRIS_POSITION_H

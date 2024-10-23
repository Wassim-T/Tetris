/**
 * @file Brick.h
 * @brief Declares the Brick class representing a Tetris brick.
 */

#ifndef TETRIS_BRICK_H
#define TETRIS_BRICK_H
#define _USE_MATH_DEFINES
#include <vector>
#include "Square.h"
#include "Color.hpp"
#include <cmath>

namespace model {

/**
     * @class Brick
     * @brief Represents a Tetris brick composed of squares.
     */
class Brick {

    std::vector<Square> _squares; ///< Vector of squares composing the brick
    Color _color; ///< Color of the brick

public:

    /**
         * @brief Constructor.
         * @param squares Vector of squares composing the brick.
         * @param color Color of the brick.
         */
    Brick(std::vector<Square>& squares, Color color);

    /**
         * @brief Default constructor.
         */
    Brick() = default;

    /**
         * @brief Rotates the brick in the specified direction.
         * @param dir Direction of rotation.
         */
    void rotate(DIRECTION2D dir);

    /**
         * @brief Moves the brick in the specified direction.
         * @param dir Direction of movement.
         */
    void move(DIRECTION2D dir);

    /**
         * @brief Gets the color of the brick.
         * @return Color of the brick.
         */
    Color getColor() const;

    /**
         * @brief Gets the y positions of all squares in the brick.
         * @return Vector of y positions.
         */
    std::vector<int> getYPositions();

    /**
         * @brief Gets the position of the square at the specified index.
         * @param index Index of the square.
         * @return Position of the square.
         */
    Position getPosOfSquare(int index) const;

    /**
         * @brief Gets the size of the vector of squares.
         * @return Size of the vector of squares.
         */
    int getListSquareSize() const;

    /**
         * @brief Moves the square with the specified position down.
         * @param pos Position of the square to move down.
         */
    void moveSquareDown(const Position& pos);

    /**
         * @brief Equality operator.
         * @param other The other brick to compare.
         * @return True if the bricks are equal, false otherwise.
         */
    bool operator==(const Brick &other) const;

private:

    /**
         * @brief Checks if the brick contains the specified square.
         * @param square Square to check for.
         * @return True if the brick contains the square, false otherwise.
         */
    bool contains(const Square &square) const;

};
}

#endif //TETRIS_BRICK_H

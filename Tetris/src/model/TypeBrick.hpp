#ifndef TETRIS_TYPEBRICK_HPP
#define TETRIS_TYPEBRICK_HPP

namespace model{

/**
     * @brief Enum representing different types of Tetris bricks.
     *
     * The TypeBrick enum class represents different types of Tetris bricks
     * that can be used in the game. Each type corresponds to a specific shape.
     */
enum class TypeBrick{
    SHAPE_I, /**< The I-shaped Tetris brick */
    SHAPE_C, /**< The C-shaped Tetris brick */
    SHAPE_T, /**< The T-shaped Tetris brick */
    SHAPE_J, /**< The J-shaped Tetris brick */
    SHAPE_L, /**< The L-shaped Tetris brick */
    SHAPE_Z, /**< The Z-shaped Tetris brick */
    SHAPE_S  /**< The S-shaped Tetris brick */
};

}

#endif // TETRIS_TYPEBRICK_HPP

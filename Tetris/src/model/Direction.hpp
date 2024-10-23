#ifndef TETRIS_DIRECTION_HPP
#define TETRIS_DIRECTION_HPP

#include <utility>

namespace model {
/**
     * @typedef DIRECTION2D
     * @brief Represents a 2D direction as a pair of integers.
     */
using DIRECTION2D = std::pair<int, int>;

/**
     * @struct DirectionStruct
     * @brief Provides constant values for common 2D directions.
     */
struct DirectionStruct {
    static constexpr DIRECTION2D UP = std::make_pair(0, -1);    ///< Upward direction
    static constexpr DIRECTION2D DOWN = std::make_pair(0, 1);   ///< Downward direction
    static constexpr DIRECTION2D LEFT = std::make_pair(-1, 0);  ///< Leftward direction
    static constexpr DIRECTION2D RIGHT = std::make_pair(1, 0);  ///< Rightward direction
};
}

#endif //TETRIS_DIRECTION_HPP

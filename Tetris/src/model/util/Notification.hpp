/**
 * @file Notification.hpp
 * @brief Defines the Notification enum class for game events.
 */

#ifndef TETRIS_NOTIFICATION_HPP
#define TETRIS_NOTIFICATION_HPP

namespace model {

/**
     * @enum Notification
     * @brief Represents various notifications for game events.
     */
enum class Notification {
    NEW_SCORE,   ///< New score notification
    NEW_POSITION,   ///< New position notification
    NEW_LEVEL,   ///< New level notification
    NEW_BRICK,   ///< New brick notification
    NEW_SOUND,   ///< New sound notification
    NEW_SHADOW,   ///< New shadow notification
    GAME_OVER,   ///< Game over notification
    WIN   ///< Win notification
};

}

#endif //TETRIS_NOTIFICATION_HPP

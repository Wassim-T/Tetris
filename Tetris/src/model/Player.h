#ifndef TETRIS_PLAYER_H
#define TETRIS_PLAYER_H

#include <string>

namespace model {

/**
     * @brief The class representing a player in the Tetris game.
     *
     * The Player class encapsulates a player's name and score.
     */
class Player {
        std::string _name; /**< The name of the player */
        int _score; /**< The score of the player */

public:
    /**
         * @brief Constructs a Player object with the specified name.
         *
         * @param name The name of the player.
         */
    Player(std::string &name);

    /**
         * @brief Sets the score of the player based on the number of lines cleared, drop height, and game level.
         *
         * Calculates the score based on the number of lines cleared, drop height, and game level,
         * and updates the player's score accordingly.
         *
         * @param nbL The number of lines cleared in a single move.
         * @param hDrop The height from which the brick was dropped.
         * @param niveau The game level.
         */
    void setScore(int nbL, int hDrop, int niveau);

    /**
         * @brief Gets the score of the player.
         *
         * @return The score of the player.
         */
    int getScore() const;

    /**
         * @brief Gets the name of the player.
         *
         * @return The name of the player.
         */
    std::string getName() const;

    /**
     * @brief setName set the username.
     * @param name the name of the player
     */
    void setName(std::string name);
};



}

#endif //TETRIS_PLAYER_H

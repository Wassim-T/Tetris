/**
 * @file TetrisController.h
 * @brief Declares the TetrisController class responsible for controlling the Tetris game.
 */

#ifndef TETRIS_TETRISCONTROLLER_H
#define TETRIS_TETRISCONTROLLER_H

#include "../model/Game.h"

namespace controller {

/**
     * @class TetrisController
     * @brief Controls the Tetris game.
     */
class TetrisController {
    std::shared_ptr<model::Game> _facade; ///< Pointer to the Tetris game facade

public:
    /**
         * @brief Constructor.
         * @param game Shared pointer to the Tetris game.
         */
    TetrisController(std::shared_ptr<model::Game> &game);

    /**
         * @brief Gets the score of the game.
         * @return The score of the game.
         */
    int getScore() const;


    int getSpeed() const;

    /**
         * @brief Gets the grid of the game.
         * @return Reference to the grid of the game.
         */
    model::GRID2D &getGrid();

    /**
         * @brief Gets the player's name.
         * @return The player's name.
         */
    std::string getPlayerName() const;

    /**
         * @brief Moves the current brick in the specified direction.
         * @param dir Direction of movement.
         */
    void moveBrick(const model::DIRECTION2D &dir);

    /**
         * @brief Moves the current brick downwards.
         */
    void moveBrick();

    /**
         * @brief Rotates the current brick in the specified direction.
         * @param dir Direction of rotation.
         */
    void rotateBrick(const model::DIRECTION2D &dir);

    /**
         * @brief Gets the current brick.
         * @return The current brick.
         */
    model::Brick getCurrentBrick() const;

    /**
         * @brief Gets the next brick.
         * @return The next brick.
         */
    model::Brick getNextBrick() const;

    /**
         * @brief Gets the shadow of the current brick.
         * @return The shadow of the current brick.
         */
    model::Brick getShadow() const;

    /**
         * @brief Gets the current level of the game.
         * @return The current level of the game.
         */
    int getLevel() const;

    /**
         * @brief Adds an observer to the game.
         * @param observer Pointer to the observer to add.
         */
    void addObserver(std::shared_ptr<model::Observer> observer);

    /**
         * @brief Drops the current brick to the lowest possible position.
         */
    void dropBrick();

    /**
     * @brief setUsername set the username.
     */
    void setUsername(std::string name);
};

}

#endif //TETRIS_TETRISCONTROLLER_H

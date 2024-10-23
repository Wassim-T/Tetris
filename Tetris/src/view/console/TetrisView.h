#ifndef TETRIS_TETRISVIEW_H
#define TETRIS_TETRISVIEW_H

#include "../../model/util/Observer.hpp"
#include "../../controller/TetrisController.h"

namespace view::console {

// Define ANSI color escape codes
#define _RESET   "\033[0m"
#define _RED     "\033[31m"
#define _GREEN   "\033[32m"
#define _YELLOW  "\033[33m"
#define _BLUE    "\033[34m"
#define _MAGENTA "\033[35m"
#define _CYAN    "\033[36m"
#define _WHITE   "\033[37m"

/**
 * @brief Class representing the console-based Tetris game view.
 *
 * The TetrisView class provides functionality to display the Tetris game
 * on the console. It inherits from the model::Observer class to receive
 * notifications from the game model and update the view accordingly.
 */
class TetrisView : public model::Observer {

    int _score; /**< Current player's score */
    int _level; /**< Current game level */
    model::Brick _currBrick; /**< Current falling Tetris brick */
    model::Brick _shadow; /**< Shadow of the falling Tetris brick */
    model::Brick _nextBrick; /**< Next Tetris brick to appear */
    controller::TetrisController _controller; /**< Controller to interact with the game */

public:
    /**
     * @brief Constructor for TetrisView.
     * @param controller The Tetris controller object.
     */
    TetrisView(const controller::TetrisController &controller);

    /**
     * @brief Print the Tetris game board.
     */
    void printBoard();

    /**
     * @brief Print the "Game Over" message.
     */
    void printLoose();

    /**
     * @brief Print the "You Win" message.
     */
    void printWin();

private:
    /**
     * @brief Update function called by the game model upon state change.
     * @param notification The notification received from the game model.
     */
    void update(model::Notification notification) override;

    /**
     * @brief Print the player's score and current level.
     */
    void printPlayer();

    /**
     * @brief Print the next Tetris brick to appear.
     */
    void printNextBrick();

};

} // namespace view::console

#endif // TETRIS_TETRISVIEW_H

/**
 * @file TetrisException.h
 * @brief Declares the TetrisException class.
 */

#ifndef TETRIS_TETRISEXCEPTION_H
#define TETRIS_TETRISEXCEPTION_H

#include <stdexcept>

namespace model {

/**
     * @class TetrisException
     * @brief Exception class for Tetris game.
     */
class TetrisException : public std::runtime_error {
public:
    /**
         * @brief Constructor.
         * @param message Error message.
         */
    TetrisException(const std::string& message);
};

}

#endif //TETRIS_TETRISEXCEPTION_H

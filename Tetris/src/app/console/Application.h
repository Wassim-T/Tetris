/**
 * @file Application.h
 * @brief Declares functions for Tetris application.
 */

#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#include <array>
#include <string>
#include <vector>

#define KEY_DOWN 80 ///< Arrow key code for down movement
#define KEY_LEFT 75 ///< Arrow key code for left movement
#define KEY_RIGHT 77 ///< Arrow key code for right movement
#define KEY_SPACE 32 ///< Key code for spacebar

/**
 * @brief Asks the user if they want to load the default configuration.
 * @return True if the user chooses to load default configuration, false otherwise.
 */
bool defaultConfiguration();

/**
 * @brief Asks the user for a value within a specified range.
 * @param lowerBound Lower bound of the range.
 * @param upperBound Upper bound of the range.
 * @param message Message to display to the user.
 * @return User-input value within the specified range.
 */
int getValueFromUser(int lowerBound, int upperBound, std::string message);

/**
 * @brief Asks the user to input shapes for the Tetris game.
 * @return Array of shapes chosen by the user.
 */
std::array<char, 7> getShapesFromUser();

/**
 * @brief Fills the shape vector based on user input.
 * @param c Character representing the shape chosen by the user.
 * @param shapes Vector to store the shapes.
 */
void fillShapeVector(const char &c, std::vector<model::TypeBrick> &shapes);

/**
 * @brief Asks the user to input their username.
 * @return User-input username.
 */
std::string askUserName();

/**
 * @brief Prints the welcome message.
 */
void printWelcome();

#endif //TETRIS_APPLICATION_H

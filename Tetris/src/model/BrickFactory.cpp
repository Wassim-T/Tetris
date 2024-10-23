/**
 * @file BrickFactory.cpp
 * @brief Implements the BrickFactory class methods.
 */

#include "BrickFactory.h"
#include "util/TetrisException.h"


namespace model {

BrickFactory::BrickFactory(int gridWidth) : _widthInitialPos(gridWidth / 2) {}

Brick BrickFactory::makeBrick(const TypeBrick &typeBrick) {



    switch (typeBrick) {
    case TypeBrick::SHAPE_C : {
        std::vector<Square> squaresC{Position(_widthInitialPos, 0), Position(_widthInitialPos + 1, 0),
                                     Position(_widthInitialPos, 1), Position(_widthInitialPos + 1, 1)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresC, Color::DARKBLUE);
        case 2 :
            return Brick(squaresC, Color::GREEN);
        case 3 :
            return Brick(squaresC, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresC, Color::MAGENTA);
        case 5 :
            return Brick(squaresC, Color::ORANGE);
        case 6 :
            return Brick(squaresC, Color::RED);
        case 7 :
            return Brick(squaresC, Color::YELLOW);
        }
    }

    case TypeBrick::SHAPE_I : {
        std::vector<Square> squaresI{Position(_widthInitialPos, 2), Position(_widthInitialPos, 0),
                                     Position(_widthInitialPos, 1), Position(_widthInitialPos, 3)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresI, Color::DARKBLUE);
        case 2 :
            return Brick(squaresI, Color::GREEN);
        case 3 :
            return Brick(squaresI, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresI, Color::MAGENTA);
        case 5 :
            return Brick(squaresI, Color::ORANGE);
        case 6 :
            return Brick(squaresI, Color::RED);
        case 7 :
            return Brick(squaresI, Color::YELLOW);
        }
    }

    case TypeBrick::SHAPE_J : {
        std::vector<Square> squaresJ{Position(_widthInitialPos, 2), Position(_widthInitialPos + 1, 2),
                                     Position(_widthInitialPos + 1, 1), Position(_widthInitialPos + 1, 0)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresJ, Color::DARKBLUE);
        case 2 :
            return Brick(squaresJ, Color::GREEN);
        case 3 :
            return Brick(squaresJ, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresJ, Color::MAGENTA);
        case 5 :
            return Brick(squaresJ, Color::ORANGE);
        case 6 :
            return Brick(squaresJ, Color::RED);
        case 7 :
            return Brick(squaresJ, Color::YELLOW);
        }
    }

    case TypeBrick::SHAPE_L : {
        std::vector<Square> squaresL{Position(_widthInitialPos, 2), Position(_widthInitialPos, 0),
                                     Position(_widthInitialPos, 1), Position(_widthInitialPos + 1, 2)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresL, Color::DARKBLUE);
        case 2 :
            return Brick(squaresL, Color::GREEN);
        case 3 :
            return Brick(squaresL, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresL, Color::MAGENTA);
        case 5 :
            return Brick(squaresL, Color::ORANGE);
        case 6 :
            return Brick(squaresL, Color::RED);
        case 7 :
            return Brick(squaresL, Color::YELLOW);
        }
    }

    case TypeBrick::SHAPE_S : {
        std::vector<Square> squaresS{Position(_widthInitialPos, 1), Position(_widthInitialPos, 0),
                                     Position(_widthInitialPos + 1, 0), Position(_widthInitialPos - 1, 1)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresS, Color::DARKBLUE);
        case 2 :
            return Brick(squaresS, Color::GREEN);
        case 3 :
            return Brick(squaresS, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresS, Color::MAGENTA);
        case 5 :
            return Brick(squaresS, Color::ORANGE);
        case 6 :
            return Brick(squaresS, Color::RED);
        case 7 :
            return Brick(squaresS, Color::YELLOW);
        }
    }

    case TypeBrick::SHAPE_T : {
        std::vector<Square> squaresT{Position(_widthInitialPos, 1), Position(_widthInitialPos, 0),
                                     Position(_widthInitialPos + 1, 1), Position(_widthInitialPos - 1, 1)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresT, Color::DARKBLUE);
        case 2 :
            return Brick(squaresT, Color::GREEN);
        case 3 :
            return Brick(squaresT, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresT, Color::MAGENTA);
        case 5 :
            return Brick(squaresT, Color::ORANGE);
        case 6 :
            return Brick(squaresT, Color::RED);
        case 7 :
            return Brick(squaresT, Color::YELLOW);
        }
    }

    case TypeBrick::SHAPE_Z : {
        std::vector<Square> squaresZ{Position(_widthInitialPos, 1), Position(_widthInitialPos, 0),
                                     Position(_widthInitialPos - 1, 0), Position(_widthInitialPos + 1, 1)};
        switch (nvs::random_value(7,1)) {
        case 1 :
            return Brick(squaresZ, Color::DARKBLUE);
        case 2 :
            return Brick(squaresZ, Color::GREEN);
        case 3 :
            return Brick(squaresZ, Color::LIGHTBLUE);
        case 4 :
            return Brick(squaresZ, Color::MAGENTA);
        case 5 :
            return Brick(squaresZ, Color::ORANGE);
        case 6 :
            return Brick(squaresZ, Color::RED);
        case 7 :
            return Brick(squaresZ, Color::YELLOW);
        }
    }

    default:
        throw TetrisException("Failed to create the instance of brick");
    }
}
}

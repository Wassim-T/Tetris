#include <catch2/catch_test_macros.hpp>
#include "model/Position.h"
#include "model/Grid.h"



TEST_CASE("GridCreation", "[Grid]") {
    model::Grid grid(10, 10, 50);
    REQUIRE(grid.getGrid().size() == 10);
    REQUIRE(grid.getGrid()[0].size() == 10);
}

// ---------------------------------------------------------------------


TEST_CASE("PositionTest", "TestMove") {
    model::Position position(0, 0);
    position = position + model::DirectionStruct::RIGHT;
    REQUIRE(position.get_x() == 1);
    REQUIRE(position.get_y() == 0);

    position = position + model::DirectionStruct::DOWN;
    REQUIRE(position.get_x() == 1);
    REQUIRE(position.get_y() == 1);

    position = position + model::DirectionStruct::LEFT;
    REQUIRE(position.get_x() == 0);
    REQUIRE(position.get_y() == 1);

    position = position + model::DirectionStruct::UP;
    REQUIRE(position.get_x() == 0);
    REQUIRE(position.get_y() == 0);
}

// ---------------------------------------------------------------------


TEST_CASE("PositionMove", "[Position]") {
    model::Position position(0, 0);

    SECTION("Move Right") {
        position = position + model::DirectionStruct::RIGHT;
        REQUIRE(position.get_x() == 1);
        REQUIRE(position.get_y() == 0);
    }

    SECTION("Move Left") {
        position = position + model::DirectionStruct::LEFT;
        REQUIRE(position.get_x() == -1);
        REQUIRE(position.get_y() == 0);
    }

}

// ---------------------------------------------------------------------


TEST_CASE("PositionNegativeValues", "[Position]") {
    model::Position position(-2, -3);

    REQUIRE(position.get_x() == -2);
    REQUIRE(position.get_y() == -3);
}

// ---------------------------------------------------------------------


TEST_CASE("PositionEqualityWithAnotherInstance", "[Position]") {
    model::Position position1(2, 4);
    model::Position position2(2, 4);

    REQUIRE(position1 == position2);

    model::Position position3(2, 4);
    model::Position position4(1, 3);

    REQUIRE_FALSE(position3 == position4);
}

// ---------------------------------------------------------------------


TEST_CASE("PositionCopyConstructor", "[Position]") {
    model::Position original(2, 4);
    model::Position copy(original);

    REQUIRE(copy.get_x() == original.get_x());
    REQUIRE(copy.get_y() == original.get_y());
}

// ---------------------------------------------------------------------

TEST_CASE("BrickRotation", "[Brick]") {

    std::vector<model::Square> squares;
    squares.push_back(model::Square(model::Position(0, 0)));
    squares.push_back(model::Square(model::Position(1, 0)));
    squares.push_back(model::Square(model::Position(0, 1)));
    squares.push_back(model::Square(model::Position(-1, 0)));

    model::Brick brick(squares, model::Color::DARKBLUE);

    SECTION("Rotate Right") {

        std::vector<model::Position> originalPositions;
        for (int i = 0; i < brick.getListSquareSize(); ++i) {
            originalPositions.push_back(brick.getPosOfSquare(i));
        }

        brick.rotate(model::DirectionStruct::RIGHT);

        REQUIRE(brick.getPosOfSquare(0) == model::Position(0, 0));
        REQUIRE(brick.getPosOfSquare(1) == model::Position(0, 1));
        REQUIRE(brick.getPosOfSquare(2) == model::Position(-1, 0));
        REQUIRE(brick.getPosOfSquare(3) == model::Position(0, -1));
    }

    SECTION("Rotate Left") {

        std::vector<model::Position> originalPositions;
        for (int i = 0; i < brick.getListSquareSize(); ++i) {
            originalPositions.push_back(brick.getPosOfSquare(i));
        }

        brick.rotate(model::DirectionStruct::LEFT);

        REQUIRE(brick.getPosOfSquare(0) == model::Position(0, 0));
        REQUIRE(brick.getPosOfSquare(1) == model::Position(0, -1));
        REQUIRE(brick.getPosOfSquare(2) == model::Position(1, 0));
        REQUIRE(brick.getPosOfSquare(3) == model::Position(0, 1));
    }
}

// ---------------------------------------------------------------------


TEST_CASE("BrickMove", "[Brick]") {
    std::vector<model::Square> squares;
    squares.push_back(model::Square(model::Position(0, 0)));
    squares.push_back(model::Square(model::Position(1, 0)));
    squares.push_back(model::Square(model::Position(0, 1)));
    squares.push_back(model::Square(model::Position(-1, 0)));

    model::Brick brick(squares, model::Color::DARKBLUE);

    SECTION("Move Right") {
        brick.move(model::DirectionStruct::RIGHT);
        REQUIRE(brick.getPosOfSquare(0) == model::Position(1, 0));
        REQUIRE(brick.getPosOfSquare(1) == model::Position(2, 0));
        REQUIRE(brick.getPosOfSquare(2) == model::Position(1, 1));
        REQUIRE(brick.getPosOfSquare(3) == model::Position(0, 0));
    }

    SECTION("Move Left") {
        brick.move(model::DirectionStruct::LEFT);
        REQUIRE(brick.getPosOfSquare(0) == model::Position(-1, 0));
        REQUIRE(brick.getPosOfSquare(1) == model::Position(0, 0));
        REQUIRE(brick.getPosOfSquare(2) == model::Position(-1, 1));
        REQUIRE(brick.getPosOfSquare(3) == model::Position(-2, 0));
    }

    SECTION("Move Down") {
        brick.move(model::DirectionStruct::DOWN);
        REQUIRE(brick.getPosOfSquare(0) == model::Position(0, 1));
        REQUIRE(brick.getPosOfSquare(1) == model::Position(1, 1));
        REQUIRE(brick.getPosOfSquare(2) == model::Position(0, 2));
        REQUIRE(brick.getPosOfSquare(3) == model::Position(-1, 1));
    }
}

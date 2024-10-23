#ifndef TETRIS_LOADER_H
#define TETRIS_LOADER_H

#include "BagBrick.h"
#include "Grid.h"
#include "TypeBrick.hpp"

namespace model {

/**
     * @brief The class responsible for loading the Tetris game components.
     *
     * The Loader class initializes the game components such as the bag of bricks
     * and the game grid based on the provided parameters.
     */
class Loader {
    BagBrick _bag; /**< The bag of bricks */
    Grid _grid; /**< The game grid */

public:
    /**
         * @brief Constructs a Loader object and initializes the game components.
         *
         * @param gridDensity The density of occupied cells in the grid.
         * @param gridWidth The width of the game grid.
         * @param gridHeight The height of the game grid.
         * @param shapesTocreate The list of shapes to create the bricks.
         */
    Loader(int gridDensity, int gridWidth, int gridHeight, std::vector<TypeBrick> shapesTocreate);

    /**
         * @brief Default constructor.
         */
    Loader() = default;

    /**
         * @brief Gets the bag of bricks.
         *
         * @return The bag of bricks.
         */
    BagBrick getBag() const;

    /**
         * @brief Gets the game grid.
         *
         * @return The game grid.
         */
    Grid getGrid() const;

private:
    /**
         * @brief Loads the game components.
         *
         * Initializes the bag of bricks and the game grid based on the provided parameters.
         *
         * @param gridDensity The density of occupied cells in the grid.
         * @param gridWidth The width of the game grid.
         * @param gridHeight The height of the game grid.
         * @param shapesTocreate The list of shapes to create the bricks.
         */
    void LoadGame(int gridDensity, int gridWidth, int gridHeight, std::vector<TypeBrick> shapesTocreate);
};

}

#endif //TETRIS_LOADER_H

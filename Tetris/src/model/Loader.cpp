    #include "Loader.h"
#include "BrickFactory.h"
#include "./util/TetrisException.h"


namespace model{

    Loader::Loader(int gridDensity, int gridWidth, int gridHeight, std::vector<TypeBrick> shapesTocreate) : _grid(gridHeight,gridWidth,gridDensity) {
            LoadGame( gridDensity, gridWidth, gridHeight, shapesTocreate);
    }

    BagBrick Loader::getBag()const
    {
        return _bag;
    }

    Grid Loader::getGrid()const{
        return _grid;
    }

    void Loader::LoadGame(int gridDensity, int gridWidth, int gridHeight, std::vector<TypeBrick> shapesTocreate) {
        if (shapesTocreate.size() > 7){
            throw TetrisException("the shape's initialization list's size is not 7 !");
        }
            nvs::randomize();
            BrickFactory factory(gridWidth);
            std::array<Brick,7> bricks;

        for (int i = 0; i < 7; ++i) {

                bricks.at(i) = factory.makeBrick(shapesTocreate.at(i));
        }
        BagBrick bag(bricks);
        _bag = bag;
    }
}




#include "Grid.h"


namespace model {
    // instancier toutes les boxes du vector dynamiquement sinon ils sont supprimer localement c'est pôur ça on a utiliser le make_unique
    Grid::Grid(int height, int width, int gridDensity) : _nbLines(0), _hDrop(0) {

        _grid.resize(height);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {

                _grid.at(i).emplace_back(std::make_shared<Box>());

            } 
        }


        int nbPositionsToFill = ((height * width) / 100) * gridDensity;
        int cpt = 0;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 1);

        for (int i = height - 1; i >= 0; --i) {

            for (int j = 0; j < width; ++j) {
                if (cpt == nbPositionsToFill) {
                    break;
                }
                int randNumber = dis(gen);
                if (randNumber == 1) {
                    _grid.at(i).at(j)->setColor(Color::GREY);
                    cpt++;
                }
            }
        }
    }

    // on verfie si ya des ligne a supprimer , on prend un set des position a enelever aprés on vérifie si les position on trouve que c'est une ligne est remplis on le rajouter dans
    // le set pour la retirer plus tard
    bool Grid::checkLine(Brick &currBrick) {
        std::vector<int> PosToCheck = currBrick.getYPositions(); //on recoit les positions Y des carrés de la forme
        std::set<int> LineToremove;
        int stop = getHighestPos(PosToCheck);
        _nbLines = 0;

        for (int i = _grid.size()-1; i >= stop ; --i) {
            if (isLine(i)) {
                LineToremove.insert(i);
                _nbLines++;
            }
        }

        if (!LineToremove.empty()) {
            for (const int &pos: LineToremove) {
                removeLine(pos);
            }

            int max = maxLine(LineToremove);

            for (int i = max - 1; i >= 0; --i) {
                int lineToCheck = i + 1;
                if (!isLineEmpty(i)) {
                    while (isLineEmpty(lineToCheck)) {
                        moveLineDown(lineToCheck - 1);

                        lineToCheck++;
                        if (lineToCheck >= _grid.size()){
                            break;
                        }
                    }
                }
            }
            return true;
        }

        return false;

    }

    void Grid::moveLineDown(int row) {

        for (int i = 0; i < _grid.at(row).size(); ++i) {

            auto box = _grid.at(row).at(i);

            if (box->isOccuped()) {
                Color tempColor = box->getColor();
                box->emptyBox();
                _grid.at(row + 1).at(i)->setColor(tempColor);
            }


        }
    }

    bool Grid::isLineEmpty(int row) {
        for (const auto &e: _grid.at(row)) {
            if (e->isOccuped()) {
                return false;
            }
        }
        return true;
    }


    void Grid::removeLine(int row) {
        auto vectorBox = _grid.at(row);
        for (auto &box: vectorBox) {
            box->emptyBox();

        }
    }

    void Grid::setShadow(Brick& currBrick) {
        int drop = 0;
        bool canMoveDown = true;

        Brick tempBrick = currBrick;


        while (canMoveDown) {
            for (int i = 0; i < tempBrick.getListSquareSize(); ++i) {

                    canMoveDown &= isValidMove(tempBrick.getPosOfSquare(i), DirectionStruct::DOWN, _grid.size(),
                                               _grid.at(0).size());
                    if (!canMoveDown) {
                        break;
                    }

            }
            if (canMoveDown) {
                for (int i = 0; i < tempBrick.getListSquareSize(); ++i) {
                    tempBrick.moveSquareDown(tempBrick.getPosOfSquare(i));
                }

                drop++;
            }
        }
        _hDrop = drop;
        _shadow = tempBrick;

    }

    int Grid::maxLine(const std::set<int>& positions) {

        int max = INT32_MIN;

        for (const auto &e: positions) {

            if (e > max) {
                max = e;
            }
        }

        return max;

    }


    bool Grid::isLine(int row) {

        for (int i = 0; i < _grid.at(row).size(); ++i) {

            if (!_grid.at(row).at(i)->isOccuped()) {
                return false;
            }
        }

        return true;
    }


    bool Grid::isValidMove(Position &pos, const DIRECTION2D &dir, int height, int width) {
        int row = pos.get_y();
        int col = pos.get_x();

        if (row + dir.second >= height || col + dir.first >= width || row + dir.second < 0 || col + dir.first < 0){
            return false;
        }


        if (_grid.at(row + dir.second).at(col + dir.first)->isOccuped()) {
            return false;
        }
        return true;
    }

    bool Grid::isValidMove(Position &&pos, const DIRECTION2D &dir, int height, int width) {
        int row = pos.get_y();
        int col = pos.get_x();

        if (row + dir.second > height - 1 || col + dir.first > width - 1 || row + dir.second < 0 ||
            col + dir.first < 0) {
            return false;
        }

        if (_grid.at(row + dir.second).at(col + dir.first)->isOccuped()) {
            return false;
        }

        return true;
    }


    int Grid::getNbLines() {
        return _nbLines;
    }

   bool Grid::isBrickPlaced(Brick &currBrick) {
      if (currBrick == _shadow) {
          for (int i = 0; i < currBrick.getListSquareSize(); ++i) {
           Position squarePos = currBrick.getPosOfSquare(i);
               _grid.at(squarePos.get_y()).at(squarePos.get_x())->setColor(currBrick.getColor());
          }
          return true;
       }
       return false;
   }

    int Grid::getHDrop() {
        return _hDrop;
    }

// bool parce que je vais mettre un sound quand on peut pas
    bool Grid::moveBrick(Brick &currBrick, const DIRECTION2D &dir) {
        for (int i = 0; i < currBrick.getListSquareSize(); i++) {
            Position pos = currBrick.getPosOfSquare(i);
            if (!isValidMove(pos, dir, _grid.size(), _grid.at(0).size())) {
                return false;
            }
        }
        currBrick.move(dir);

        if (dir != DirectionStruct::DOWN) {
            setShadow(currBrick);
        }

        return true;
    }

    bool Grid::rotateBrick(Brick &currBrick, const DIRECTION2D &dir) {

        Brick tempBrick = currBrick;

        tempBrick.rotate(dir);

        for (int i = 0; i < tempBrick.getListSquareSize(); ++i) {
            Position pos = tempBrick.getPosOfSquare(i);
            if (checkOutOfBounds(pos)){
                return false;
            }
            if (_grid.at(pos.get_y()).at(pos.get_x())->isOccuped()){
                return false;
            }
        }

        currBrick = tempBrick;

        setShadow(currBrick);

        return true;
    }

    //bool parce que ca verifie aussi en meme temps qu'on peut spawn ou pas pour plus d'efficacité et ducoup faire la verif
    // et le spawn en meme temps
    bool Grid::spawnBrick(Brick &currBrick) {

        std::vector<Position> positions;
        for (int i = 0; i < currBrick.getListSquareSize(); ++i) {
            Position pos = currBrick.getPosOfSquare(i);
            if (_grid.at(pos.get_y()).at(pos.get_x())->isOccuped()) {
                return false;
            }
            positions.push_back(pos);
        }

        setShadow(currBrick);

        return true;
    }

    GRID2D & Grid::getGrid(){
        return _grid;
    }

    Brick Grid::getShadow()  {
        return _shadow;
    }

    bool Grid::checkOutOfBounds(Position &pos) {
        if (pos.get_y() < 0 || pos.get_x() < 0){
            return true;
        }
        if (pos.get_y() >= _grid.size() || pos.get_x() >= _grid.at(0).size()){
            return true;
        }

        return false;
    }

    int Grid::getHighestPos(std::vector<int> &positions) {
        int highest = 9999;
        for (int &pos : positions){
            if (pos<highest){
                highest = pos;
            }
        }
        return highest;
    }

    void Grid::dropBrick(Brick & currBrick){
        currBrick = _shadow;
    }

}



#include "Brick.h"

namespace model{
Brick::Brick( std::vector<Square>& squares, Color color) : _squares(squares), _color(color){}

void Brick::rotate(DIRECTION2D dir) {
    


    // Define the angle of rotation
    double angle = (dir == DirectionStruct::LEFT ) ? -M_PI / 2.0 : M_PI / 2.0;

    Position center = _squares.at(0).getPos();


    for (auto& square : _squares) {
        if (square.getPos() != center) {
            int dx = square.getPos().get_x() - center.get_x();
            int dy = square.getPos().get_y() - center.get_y();

            int rotatedX = round(dx * cos(angle) - dy * sin(angle));
            int rotatedY = round(dx * sin(angle) + dy * cos(angle));
            square.modifyPos() = Position(rotatedX + center.get_x(),rotatedY +center.get_y());

        }
    }
}

void Brick::move(DIRECTION2D dir){
    for (Square & s : _squares){
        s.modifyPos()+dir;
    }
}

Color Brick::getColor() const {
    return _color;
}

std::vector<int> Brick::getYPositions(){
    std::vector<int> yPositions;
    for (auto& e : _squares){
        yPositions.push_back(e.getPos().get_y());
    }
    return yPositions;
}

void Brick::moveSquareDown(const Position& pos) {
    for (auto & square : _squares) {
        if (square.getPos() == pos) {
            square.modifyPos() = square.modifyPos() + DirectionStruct::DOWN;
            break;
        }
    }
}

int Brick::getListSquareSize() const{
    return _squares.size();
}

Position Brick::getPosOfSquare(int index) const{
    return _squares.at(index).getPos();
}

bool Brick::operator==(const Brick &other) const {
    if (this->_squares == other._squares){

    }
    for(const auto square : _squares){
        if (!other.contains(square)){
            return false;
        }
    }
    return true;
}

bool Brick::contains(const Square &square) const {
    for (const auto &sq : _squares){
        if (square == sq){
            return true;
        }
    }
    return false;
}

}

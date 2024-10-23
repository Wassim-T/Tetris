#include "Square.h"

namespace model{

    Square::Square(Position& pos) : _pos(pos){}


    Position Square::getPos() const {
        return _pos;
    }

    Position& Square::modifyPos()
    {
        return _pos;
    }

    Square::Square(Position &&pos): _pos(std::move(pos)) {}

    bool Square::operator==(const Square &other) const {
        return this->_pos == other._pos;
    }
};

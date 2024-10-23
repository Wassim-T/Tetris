#include "Position.h"


namespace model {
    Position::Position(int x, int y) : _pos(std::make_pair(x, y)) {
    }

    int Position::get_x() const {
        return _pos.first;
    }

    int Position::get_y() const {
        return _pos.second;
    }

    bool Position::operator==(const Position& pos2) const {
        return _pos == pos2._pos;
    }

    Position Position::operator+(const DIRECTION2D &d) {
        _pos.first += d.first;
        _pos.second += d.second;
        return *this;
    }
}

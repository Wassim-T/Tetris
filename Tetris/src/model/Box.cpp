/**
 * @file Box.cpp
 * @brief Implements the Box class methods.
 */

#include "Box.h"

namespace model {

bool Box::isOccuped() {
    return _color.has_value();
}

void Box::emptyBox() {
    _color = std::nullopt;
}

Color Box::getColor() {
    if (_color.has_value()){
        return _color.value();
    }
    else{
        throw TetrisException("Can't get the color, it has no value");
    }
}

void Box::setColor(const Color &color) {
    _color = color;
}

}

#include "TetrisException.h"

namespace model{
    TetrisException::TetrisException(const std::string &message) : runtime_error(message) {}
}



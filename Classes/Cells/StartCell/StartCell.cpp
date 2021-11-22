#include "StartCell.h"

TypeCell StartCell::getTypeCell() const {
    return TStartCell;
}

unq_p<ICell> StartCell::clone() {
    return _universal_clone<StartCell>();
}

StartCell::StartCell(bool passable) : NormalCell(passable) {
}

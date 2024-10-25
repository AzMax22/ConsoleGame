#include "EndCell.h"
#include "Player.h"

TypeCell EndCell::getTypeCell() const{
    return TEndCell;
}

unq_p<ICell> EndCell::clone() {
    return _universal_clone<EndCell>();
}

EndCell::EndCell(bool passable) : NormalCell(passable) {
}


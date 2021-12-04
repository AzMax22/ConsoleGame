#ifndef CONSOLE_GAME_VIEWCELL_H
#define CONSOLE_GAME_VIEWCELL_H

#include "ICell.h"
#include "ViewGame.h"


class ViewCell {
    ICell* m_cell = nullptr;

    ColorText _convertToColorPair(int front, int back);
public:
    ViewCell() = default;
    void setModel(ICell& cell);
    void draw();
};


#endif //CONSOLE_GAME_VIEWCELL_H

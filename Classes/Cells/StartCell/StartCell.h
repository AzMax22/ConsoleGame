#ifndef CONSOLE_GAME_STARTCELL_H
#define CONSOLE_GAME_STARTCELL_H

#include "NormalCell.h"


class StartCell : public NormalCell {

public:
    StartCell(bool passable = true);
    //фун. возвращает тип обьекта через enum TypeCell
    TypeCell getTypeCell() const override;
    //возфращает указатель на копию обьекта в дин. памяти
    unq_p<ICell> clone() override;
};


#endif //CONSOLE_GAME_STARTCELL_H

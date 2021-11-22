#ifndef CONSOLE_GAME_ENDCELL_H
#define CONSOLE_GAME_ENDCELL_H

#include "NormalCell.h"

class EndCell : public NormalCell {

public:
    EndCell( bool passable = true);
    //фун. возвращает тип обьекта через enum TypeCell
    TypeCell getTypeCell() const override;

    //возфращает указатель на копию обьекта в дин. памяти
    unq_p<ICell> clone() override;
};


#endif //CONSOLE_GAME_ENDCELL_H

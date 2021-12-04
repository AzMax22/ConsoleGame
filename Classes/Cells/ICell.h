#ifndef CONSOLE_GAME_ICELL_H
#define CONSOLE_GAME_ICELL_H

#include "unq_p.h"
#include "AttackedObj.h"

class IItem;
class ICreature;
class Field;

enum TypeCell {
    TNormalCell,
    TStartCell,
    TEndCell,
    TImpassableCell
};

class ICell : public AttackedObj{
public:
    //Возможность положить/просм/взять предмет (зелье, мечь, броня)
    virtual void putItem(unq_p<IItem> item) = 0;
    virtual IItem* topItem() = 0;
    virtual unq_p<IItem> popItem() = 0;

    //возможность какого-то существа(nps,enemies, character) наступить на/уйти с клетки
    virtual void putCreature(ICreature* creature) = 0;
    virtual ICreature* topCreature() = 0;
    virtual ICreature* popCreature() = 0;

    //фун. возвращает тип обьекта через enum TypeCell
    virtual TypeCell getTypeCell() const = 0 ;

    //возфращает указатель на копию обьекта в дин. памяти
    virtual unq_p<ICell> clone() = 0;

    virtual bool getPassable() = 0;

    //виртуальный деструктор , чтобы коректно удалялись наследники
    virtual ~ICell() = default;
};

#endif //CONSOLE_GAME_ICELL_H

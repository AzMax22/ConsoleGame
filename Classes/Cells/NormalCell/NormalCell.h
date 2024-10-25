#ifndef CONSOLE_GAME_NORMALCELL_H
#define CONSOLE_GAME_NORMALCELL_H

#include "ICell.h"
#include "IItem.h"


class NormalCell : public ICell  {
protected:
    bool m_passable;
    unq_p<IItem> m_item = nullptr;
    ICreature* m_creature = nullptr;

    template<class T>
    //функция клонирования клетки не зависящая от класса, применима к наследникам
    unq_p<ICell> _universal_clone();

public:


    NormalCell(bool passable = true) ;

    //Возможность положить/просм/взять предмет (зелье, мечь, броня)
    void putItem(unq_p<IItem> item) override;
    IItem* topItem() override;
    unq_p<IItem> popItem() override;

    //возможность какого-то существа(nps,enemies, character) наступить на/уйти с клетки
    void putCreature(ICreature* creature) override;
    ICreature* topCreature() override;
    ICreature* popCreature() override;

    //фун. возвращает тип обьекта через enum TypeCell
    TypeCell getTypeCell() const override;

    bool getPassable() override;

    //возфращает указатель на копию обьекта в дин. памяти
    unq_p<ICell> clone() override;
};





//хз почему , но определять шаблон нужно в заголовке
template<typename T>
unq_p<ICell> NormalCell::_universal_clone() {
    unq_p<ICell> p_copy_cell = std::make_unique<T>(m_passable);

    //if (m_creature != nullptr){
      //  p_copy_cell->putCreature(m_creature);
    //}

    return p_copy_cell;
}
#endif //CONSOLE_GAME_NORMALCELL_H

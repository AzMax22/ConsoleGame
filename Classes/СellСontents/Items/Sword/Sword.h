#ifndef CONSOLE_GAME_SWORD_H
#define CONSOLE_GAME_SWORD_H

#include "IItem.h"

class Sword : public IItem{
    int m_inc_damage = 10;
public:
     void affect(ICreature* creature) override;

     unq_p<IItem> clone() override;

     TypeItem getTypeItem() const override ;

     std::string name() override;
};


#endif //CONSOLE_GAME_SWORD_H

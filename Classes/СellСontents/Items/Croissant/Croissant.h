#ifndef CONSOLE_GAME_CROISSANT_H
#define CONSOLE_GAME_CROISSANT_H

#include "IItem.h"

class Croissant : public IItem {
    int m_inc_health = 20;
public:
    void affect(ICreature* creature) override;

    unq_p<IItem> clone() override;

    TypeItem getTypeItem() const override ;

    std::string name() override;
};


#endif //CONSOLE_GAME_CROISSANT_H

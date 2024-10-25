#ifndef CONSOLE_GAME_SHIELD_H
#define CONSOLE_GAME_SHIELD_H

#include "IItem.h"




class Shield : public IItem {
    int m_inc_armor = 10;

public:
    void affect(ICreature* creature) override;

    unq_p<IItem> clone() override;

    TypeGameObj getTypeItem() const override ;

    std::string name() override;
};


#endif //CONSOLE_GAME_SHIELD_H

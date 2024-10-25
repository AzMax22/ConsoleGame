//
// Created by maxim on 23.10.2021.
//

#include "Shield.h"

void Shield::affect(ICreature *creature) {
    EventAffect event(this, creature);
    notify<EventAffect>(event);

    creature->increaseArmor(m_inc_armor);
    deleteItem();
}

unq_p<IItem> Shield::clone() {
    auto new_shield = std::make_unique<Shield>();
    return new_shield;
}

TypeGameObj Shield::getTypeItem() const {
    return TShield;
}

std::string Shield::name() {
    return "Щит ";
}

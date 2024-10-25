//
// Created by maxim on 22.10.2021.
//

#include "Sword.h"


void Sword::affect(ICreature *creature) {
    EventAffect event(this, creature);
    notify<EventAffect>(event);

    creature->increaseDamage(m_inc_damage);
    deleteItem();
}


unq_p<IItem> Sword::clone() {
    auto new_sword = std::make_unique<Sword>();
    return new_sword;
}

TypeGameObj Sword::getTypeItem() const {
    return TSword;
}

std::string Sword::name() {
    return "Меч ";
}

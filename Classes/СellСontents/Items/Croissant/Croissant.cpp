
#include "Croissant.h"

void Croissant::affect(ICreature *creature) {
    EventAffect event(this, creature);
    notify<EventAffect>(event);

    creature->increaseMaxHealth(m_inc_health);
    deleteItem();
}

unq_p<IItem> Croissant::clone() {
    auto new_sword = std::make_unique<Croissant>();
    return new_sword;
}

TypeGameObj Croissant::getTypeItem() const {
    return TCroissant;
}

std::string Croissant::name() {
    return "Куасан ";
}

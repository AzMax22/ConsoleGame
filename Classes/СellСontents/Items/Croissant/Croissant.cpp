
#include "Croissant.h"

void Croissant::affect(ICreature *creature) {
    EventAffect event(this, creature);
    notify<EventAffect>(event);

    creature->increaseHealth(m_inc_health);
}

unq_p<IItem> Croissant::clone() {
    auto new_sword = std::make_unique<Croissant>();
    return new_sword;
}

TypeItem Croissant::getTypeItem() const {
    return TCroissant;
}

std::string Croissant::name() {
    return "Куасан ";
}

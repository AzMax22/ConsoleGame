//
// Created by maxim on 16.11.2021.
//

#include "Event.h"
///////////////////////////////////////// IEvent ////////////////////////////////////////////////////
IEvent::IEvent(GameObject* obj){
    m_obj = obj;
}

GameObject& IEvent::getObjEvent() {
    return *m_obj;
}


//////////////////////////////////// EventMove ////////////////////////////////////////////////////
EventMove::EventMove(GameObject* obj,int inc_x, int inc_y) : IEvent(obj) {
    m_inc_x = inc_x;
    m_inc_y = inc_y;
}

int EventMove::getIncX() {
    return m_inc_x;
}

int EventMove::getIncY() {
    return m_inc_y;
}

//////////////////////////////////// EventReversal ////////////////////////////////////////////////////
EventReversal::EventReversal(GameObject *obj) : IEvent(obj) {

}

//////////////////////////////////// EventChangeHealth ////////////////////////////////////////////////////
EventChangeHealth::EventChangeHealth(GameObject *obj, int inc_health) : IEvent(obj) {
    m_inc_health = inc_health;
}

int EventChangeHealth::getIncHealth() {
    return m_inc_health;
}

//////////////////////////////////// EventChangeArmor ////////////////////////////////////////////////////
EventChangeArmor::EventChangeArmor(GameObject *obj, int inc_armor): IEvent(obj) {
    m_inc_armor = inc_armor;
}

int EventChangeArmor::getIncArmor() {
    return m_inc_armor;
}

//////////////////////////////////// EventChangeDamage ////////////////////////////////////////////////////
EventChangeDamage::EventChangeDamage(GameObject *obj, int inc_damage): IEvent(obj) {
    m_inc_damage = inc_damage;
}

int EventChangeDamage::getIncDamage() {
    return m_inc_damage;
}

//////////////////////////////////// EventToAttack ////////////////////////////////////////////////////
EventToAttack::EventToAttack(GameObject *obj, GameObject *another_obj): IEvent(obj) {
   m_another_obj = another_obj;
}

GameObject &EventToAttack::getAnotherObj() {
    return *m_another_obj;
}

//////////////////////////////////// EventSetLocation ////////////////////////////////////////////////////
EventSetLocation::EventSetLocation(GameObject *obj) : IEvent(obj) {

}

//////////////////////////////////// EventDeath ////////////////////////////////////////////////////
EventDeath::EventDeath(GameObject *obj) : IEvent(obj) {

}

//////////////////////////////////// EventAffect ////////////////////////////////////////////////////
EventAffect::EventAffect(GameObject *obj, GameObject *another_obj): IEvent(obj) {
    m_another_obj = another_obj;
}

GameObject &EventAffect::getAnotherObj() {
    return *m_another_obj;
}

//////////////////////////////////// EventEndGame ////////////////////////////////////////////////////
EventEndGame::EventEndGame(GameObject* obj): IEvent(obj) {

}

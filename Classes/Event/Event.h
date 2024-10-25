//
// Created by maxim on 16.11.2021.
//

#ifndef CONSOLE_GAME_EVENT_H
#define CONSOLE_GAME_EVENT_H

#include "GameObject.h"


///////////////////////////////////////// IEvent ////////////////////////////////////////////////////
class IEvent{
    GameObject* m_obj;
public:
    IEvent(GameObject* obj);
    GameObject& getObjEvent();
};


//////////////////////////////////// EventMove ////////////////////////////////////////////////////
class EventMove : public IEvent{
    int m_inc_x;
    int m_inc_y;
public:
    EventMove(GameObject* obj,int inc_x, int inc_y);

    int getIncX();
    int getIncY();

};

//////////////////////////////////// EventReversal ////////////////////////////////////////////////////
class EventReversal : public IEvent{

public:
    EventReversal(GameObject* obj);

};

//////////////////////////////////// EventChangeHealth ////////////////////////////////////////////////////
class EventChangeHealth : public IEvent{
    int m_inc_health;
public:
    EventChangeHealth(GameObject* obj, int inc_health);

    int getIncHealth();

};

//////////////////////////////////// EventChangeMaxHealth ////////////////////////////////////////////////////
class EventChangeMaxHealth : public IEvent{
    int m_inc_health;
public:
    EventChangeMaxHealth(GameObject* obj, int inc_health);

    int getIncHealth();

};

//////////////////////////////////// EventChangeArmor ////////////////////////////////////////////////////
class EventChangeArmor : public IEvent{
    int m_inc_armor;
public:
    EventChangeArmor(GameObject* obj, int inc_armor);

    int getIncArmor();

};

//////////////////////////////////// EventChangeDamage ////////////////////////////////////////////////////
class EventChangeDamage : public IEvent{
    int m_inc_damage;
public:
    EventChangeDamage(GameObject* obj, int inc_damage);

    int getIncDamage();

};

//////////////////////////////////// EventToAttack ////////////////////////////////////////////////////
class EventToAttack : public IEvent{
    GameObject* m_another_obj;
public:
    EventToAttack(GameObject* obj, GameObject* another_obj);

    GameObject& getAnotherObj();

};

//////////////////////////////////// EventSetLocation ////////////////////////////////////////////////////
class EventSetLocation : public IEvent{
public:
    EventSetLocation(GameObject* obj);
};

//////////////////////////////////// EventDeath ////////////////////////////////////////////////////
class EventDeath : public IEvent{
public:
    EventDeath(GameObject* obj);
};

//////////////////////////////////// EventAffect ////////////////////////////////////////////////////
class EventAffect : public IEvent{
    GameObject* m_another_obj;
public:
    EventAffect(GameObject* obj, GameObject* another_obj);

    GameObject& getAnotherObj();
};

//////////////////////////////////// EventEndGame ////////////////////////////////////////////////////
class EventEndGame : public IEvent{
public:
    EventEndGame(GameObject* obj);
};
#endif //CONSOLE_GAME_EVENT_H

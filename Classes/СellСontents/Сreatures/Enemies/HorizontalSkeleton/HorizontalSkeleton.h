#ifndef CONSOLE_GAME_HORIZONTALSKELETON_H
#define CONSOLE_GAME_HORIZONTALSKELETON_H

#include "ICreature.h"
#include "unq_p.h"
#include "GameObject.h"
#include "Observable.h"

class HorizontalSkeleton : public ICreature{
    //int    m_max_health = 50;
    //int    m_health = 50;
    //int    m_armor = 5;
    //int    m_damage = 10;
    //bool   m_alive = true;
    bool  m_patrollingRight = true; //в какую сторону идет скелет
    void _move(ICell& next_cell, int inc);
public:
    HorizontalSkeleton();
    void update() override; //реализация поведения
    TypeGameObj getTypeCreature() const override; //фун. возвращает тип обьекта через enum TypeCell
    bool getPatrollingRight();

    std::string name() override;

    ~HorizontalSkeleton() override = default ;
};


#endif //CONSOLE_GAME_HORIZONTALSKELETON_H

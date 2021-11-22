#ifndef CONSOLE_GAME_VERTICALSCORPION_H
#define CONSOLE_GAME_VERTICALSCORPION_H

#include "ICreature.h"
#include "GameObject.h"

class VerticalScorpion : public ICreature{
    //int    m_max_health = 30;
    //int    m_health = 30;
    //int    m_armor = 5;
    //int    m_damage = 20;
    //bool   m_alive = true;
    bool  m_patrollingTop = true; //в какую сторону идет скелет
public:
    VerticalScorpion();
    void update() override; //реализация поведения
    TypeCreature getTypeCreature() const override; //фун. возвращает тип обьекта через enum TypeCell
    bool getPatrollingTop();

    std::string name() override;

    ~VerticalScorpion() override = default ;
};


#endif //CONSOLE_GAME_VERTICALSCORPION_H

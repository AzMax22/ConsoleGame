#ifndef CONSOLE_GAME_CLEVERALIEN_H
#define CONSOLE_GAME_CLEVERALIEN_H

#include "ICreature.h"
#include "Player.h"



class CleverAlien : public ICreature {
    //int    m_max_health = 60;
    //int    m_health = 60;
    //int    m_armor = 5;
    //int    m_damage = 5;
    //bool   m_alive = true;
    Player* m_player;

    void _move(ICell& next_cell, int inc_x,int inc_y);
public:
    CleverAlien(Player* player = nullptr);
    void follow(Player* player);
    void update() override; //реализация поведения
    TypeGameObj getTypeCreature() const override; //фун. возвращает тип обьекта через enum TypeCell

    std::string name() override;

    ~CleverAlien() override = default ;
};
#endif //CONSOLE_GAME_CLEVERALIEN_H

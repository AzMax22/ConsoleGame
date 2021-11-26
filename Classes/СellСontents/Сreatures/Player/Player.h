#ifndef CONSOLE_GAME_PLAYER_H
#define CONSOLE_GAME_PLAYER_H

#include "ICreature.h"
//#include "GameObject.h"

//class BuilderField;

class Player : public ICreature{
    //int    m_max_health = 100;
    //int    m_health = 100;
    //int    m_armor = 0;
    //int    m_damage = 10;
    //bool   m_alive = true;


public:
    Player();

    void move(int inc_x,int inc_y);

    void increaseMaxHealth (int inc_max_health);  //увеличить максимальное кол-во XP
    void decreaseMaxHealth (int dec_max_health);  //уменьшить максимальное кол-во XP

    void update() override ; //реализация поведения(отсутствует)

    TypeCreature getTypeCreature() const override; //фун. возвращает тип обьекта через enum TypeCell

    int getX();
    int getY();


    std::string name() override;


    ~Player() = default;

    void setLocation(int x, int y, Field* field) override;

    //friend BuilderField;
};


#endif //CONSOLE_GAME_PLAYER_H

#ifndef CONSOLE_GAME_PLAYER_H
#define CONSOLE_GAME_PLAYER_H

#include "ICreature.h"
#include "IItem.h"
#include "GameObject.h"

class BuilderField;

class Player : public ICreature{
    //int    m_max_health = 100;
    //int    m_health = 100;
    //int    m_armor = 0;
    //int    m_damage = 10;
    //bool   m_alive = true;

    bool   m_finish = false;
        //в последдствии когда будет реализован Observable,
        //нужно перенести ответственость за проверку на EndCell,
        //которая будет уведомлять World ,о том что игрок достиг конечной клетки
        //и убрать игрока из коллекции автономных обьектов
        //в том числе и очистить Player::update()
        void setLocation(int x, int y, Field* field) override;
public:
    Player();

    void increaseMaxHealth (int inc_max_health);  //увеличить максимальное кол-во XP
    void decreaseMaxHealth (int dec_max_health);  //уменьшить максимальное кол-во XP

    void update() override ; //реализация поведения(отсутствует)

    void takeItem(); //взять предмет

    TypeCreature getTypeCreature() const override; //фун. возвращает тип обьекта через enum TypeCell

    int getX();
    int getY();

    bool win();

    std::string name() override;

    ~Player() = default;

    friend BuilderField;
};


#endif //CONSOLE_GAME_PLAYER_H

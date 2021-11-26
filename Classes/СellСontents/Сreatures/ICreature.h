#ifndef CONSOLE_GAME_ICREATURE_H
#define CONSOLE_GAME_ICREATURE_H

#include "unq_p.h"
#include "IAutonomy.h"
#include "LocatedObject.h"
#include "Field.h"

enum TypeCreature {
    TPlayer,
    THorizontalSkeleton,
    TVerticalScorpion,
    TCleverAlien
};


//интерфейс для обектов которые могут стоять на (содержатся в) Cell
class ICreature : public IAutonomy, public LocatedObject{
protected:
    int m_max_health ;
    int m_health ;
    int m_armor ;
    int m_damage ;

    int m_x, m_y; //координаты на поле
    Field* m_field; //указатель на поле
    bool m_located = false; //для единоразового размещения одного обьекта
public:
    ICreature();

    virtual void  toDamage(ICreature* enemy); //нанести урон

    virtual void increaseHealth(int inc_health); // востановить здоровье
    virtual void decreaseHealth(int dec_health);  //получить урон

    virtual void increaseArmor (int inc_armor);  //увеличить кол-во брони
    virtual void decreaseArmor (int dec_armor);  //уменьшить кол-во брони

    virtual void increaseDamage (int inc_damage);  //увеличить  урон
    virtual void decreaseDamage (int dec_damage);  //уменьшить  урон

    void death() override;

    virtual void setLocation(int x, int y, Field* field); //размещение обекта на поле

    int getX() override;
    int getHealth();
    int getMaxHealth();
    int getArmor();
    int getDamage();
    int getY() override;

    //фун. возвращает тип обьекта через enum TypeCreature
    virtual TypeCreature getTypeCreature() const = 0 ;

    ~ICreature() override = default ;
};

#endif //CONSOLE_GAME_ICREATURE_H

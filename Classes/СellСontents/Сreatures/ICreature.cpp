#include "ICreature.h"
#include "Field.h"

//////////////////////Реализация по умолчанию//////////////////////////////

void ICreature::increaseHealth(int inc_health) {
    m_health += inc_health;
    if (m_health > m_max_health){
        m_health = m_max_health ;
    }

    EventChangeHealth event(this, inc_health);
    notify<EventChangeHealth>(event);
}

void ICreature::decreaseHealth(int dec_health) {
    int real_dec_health = dec_health - m_armor; //учет защиты
    if (real_dec_health <= 0) {return;}

    m_health -= real_dec_health;
    if (m_health <= 0){
        m_health = 0;

        EventChangeHealth  event(this, -dec_health);
        notify(event);
        death();

    } else {
        EventChangeHealth  event(this, -dec_health);
        notify(event);
    }

}

void ICreature::increaseArmor(int inc_armor) {
    m_armor += inc_armor;

    EventChangeArmor event(this, inc_armor);
    notify<EventChangeArmor>(event);
}

void ICreature::decreaseArmor(int dec_armor) {
    m_armor -= dec_armor;
    if (m_armor < 0){
        m_armor = 0;
    }

    EventChangeArmor event(this, -dec_armor);
    notify<EventChangeArmor>(event);
}

void ICreature::increaseDamage(int inc_damage) {
    m_damage += inc_damage;

    EventChangeDamage event(this, inc_damage);
    notify<EventChangeDamage>(event);
}

void ICreature::decreaseDamage(int dec_damage) {
    m_damage -= dec_damage;
    if (m_damage < 0){
        m_damage = 0;
    }

    EventChangeDamage event(this, -dec_damage);
    notify<EventChangeDamage>(event);
}

void ICreature::toDamage(ICreature* enemy) {
    EventToAttack event(this, enemy);
    notify<EventToAttack>(event);

    enemy->decreaseHealth(m_damage);

}

void ICreature::setLocation(int x, int y, Field* field) {
    if (m_located == false){  //проверка на одноразовое расположение

        if (field->getCell(x, y).topCreature() == nullptr){ //проверка на пустоту клетки
            m_x = x;
            m_y = y;
            m_field = field;
            m_field->getCell(m_x, m_y).putCreature(this);
            m_located = true;

            EventSetLocation event(this);
            notify<EventSetLocation>(event);
        }else {throw std::runtime_error("Cell have  already  ICreature");}

    } else {throw std::runtime_error("Double ICreature located");}
}

void ICreature::death() {
    m_field->getCell(m_x, m_y).popCreature();
    m_alive = false;

    EventDeath event(this);
    notify<EventDeath>(event);
}

ICreature::ICreature() : GameObject() {

}

int ICreature::getX() {
    return m_x;
}

int ICreature::getY() {
    return m_y;
}

int ICreature::getHealth() {
    return m_health;
}

int ICreature::getMaxHealth() {
    return m_max_health;
}

int ICreature::getArmor() {
    return m_armor;
}

int ICreature::getDamage() {
    return m_damage;
}


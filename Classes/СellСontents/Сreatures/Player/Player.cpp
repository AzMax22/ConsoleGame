#include "Player.h"
#include "Field.h"
#include "IItem.h"

Player::Player() : ICreature() {
    m_max_health = 50;
    m_health = 50;
    m_armor = 2;
    m_damage = 10;
    m_step_duration = 2;
    m_time_last_step = 0;

}


void Player::increaseMaxHealth(int inc_max_health) {
    m_max_health += inc_max_health;
}

void Player::decreaseMaxHealth(int dec_max_health) {
    m_max_health += dec_max_health;
}


TypeCreature Player::getTypeCreature() const {
    return TPlayer;
}

void Player::update() {
    increaseHealth(1);//реген
    m_time_last_step++;
}



void Player::setLocation(int x, int y, Field *field) {
    field->buildStartCell(x,y);
    ICreature::setLocation(x, y, field);


}

int Player::getX() {
    return m_x;
}

int Player::getY() {
    return m_y;
}

std::string Player::name() {
    return "Игрок ";
}

void Player::move(int inc_x, int inc_y) {
    if (m_time_last_step < m_step_duration){
        return;
    }

    ICell& next_cell = m_field->getCell(m_x + inc_x, m_y + inc_y);

    if (next_cell.getPassable() == false) {  //проверка на проходимость след клетки
        return;
    }

    if (next_cell.topCreature()) {  //проверка есть ли существо на след клетке
        return;
    }

    ICreature* myself = m_field->getCell(m_x, m_y).popCreature();
    m_x = m_x + inc_x;
    m_y = m_y + inc_y;
    m_field->getCell(m_x, m_y ).putCreature(myself);
    m_time_last_step = 0;//сброс времени с последнего шага

    if (next_cell.topItem()) {  //проверка есть предмет
        next_cell.popItem()->affect(this); //подбор предмета
    }

    EventMove event(this, inc_x , inc_y);
    notify<EventMove>(event);
}





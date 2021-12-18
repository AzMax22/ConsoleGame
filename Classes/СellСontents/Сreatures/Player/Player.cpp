#include "Player.h"
#include "Field.h"
#include "IItem.h"

Player::Player() : ICreature() {
    m_max_health = 50;
    m_health = 50;
    m_armor = 2;
    m_damage = 15;
    m_interval_steps = 4; // интервал между шагами
    m_time_last_step = 0;
    m_interval_attacks = 15; //интервал между атаками
    m_time_last_attack = 0;
    m_interval_regen = 30; //интервал между регеном
    m_time_last_regen = 0;
}


void Player::increaseMaxHealth(int inc_max_health) {
    m_max_health += inc_max_health;
}

void Player::decreaseMaxHealth(int dec_max_health) {
    m_max_health += dec_max_health;
}


TypeGameObj Player::getTypeCreature() const {
    return TPlayer;
}

void Player::update() {
    //нанесение урона
    if (m_time_last_regen < m_interval_regen) {//задержка атаки
        m_time_last_regen++;
    } else {
        m_time_last_regen = 0;
        increaseHealth(1);//реген
    }

    if (m_time_last_step < m_interval_steps) {
        m_time_last_step++;
    }
    if (m_time_last_attack < m_interval_attacks){
        m_time_last_attack++;
    }
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

    if (m_time_last_step < m_interval_steps){//замедление шага
        return;
    }

    if ((inc_x != m_horizontal_direction)or(inc_y != m_vertical_direction)){
        m_horizontal_direction = inc_x;
        m_vertical_direction = inc_y;
        m_time_last_step = 0;//сброс времени с последнего шага
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

int Player::getVerticalDirection() {
    return m_vertical_direction;
}

int Player::getHorizontalDirection() {
    return m_horizontal_direction;
}

void Player::attack() {
    if (m_time_last_attack < m_interval_attacks) {//задержка атаки
        return;
    }
    m_time_last_attack = 0;

    ICell& next_cell = m_field->getCell(m_x + m_horizontal_direction, m_y + m_vertical_direction);

    if (next_cell.topCreature()) {  //проверка есть ли существо на след клетке
        toDamage(next_cell.topCreature());
        return;
    }

    next_cell.viewAttacked(); //5 тактов будет показыватся атака клетки
}

std::string Player::save() {
    std::ostringstream res;

    res << m_interval_regen << " "; //интервал между регеном
    res << m_time_last_regen << " ";

    return ICreature::save() + res.str();
}





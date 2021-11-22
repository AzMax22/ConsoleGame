#include "Player.h"
#include "Field.h"

Player::Player() : ICreature() {
    m_max_health = 50;
    m_health = 50;
    m_armor = 2;
    m_damage = 10;

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

    if (m_field->getCell(m_x, m_y).getTypeCell() == TEndCell) {
        m_finish = true;
    }
}

void Player::takeItem() {
    unq_p<IItem> item = m_field->getCell(m_x, m_y).popItem();
    item->affect(this);
    item.reset();
}

void Player::setLocation(int x, int y, Field *field) {
    ICreature::setLocation(x, y, field);
}

int Player::getX() {
    return m_x;
}

int Player::getY() {
    return m_y;
}

bool Player::win() {
    return m_finish;
}

std::string Player::name() {
    return "Игрок ";
}





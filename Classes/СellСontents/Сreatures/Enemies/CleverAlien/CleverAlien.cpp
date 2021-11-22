#include <cmath>
#include "CleverAlien.h"

CleverAlien::CleverAlien(Player* player) : ICreature(){
    m_player = player;
    m_max_health = 60;
    m_health = 60;
    m_armor = 5;
    m_damage = 20;
}

void CleverAlien::update() {
    int d_x =  m_player->getX()  - m_x;
    int d_y =  m_player->getY() - m_y;


    float len_vect = sqrt(d_x * d_x + d_y * d_y);

    if (len_vect > 5.5) {
        return;
    }

    int abs_d_x = abs(d_x);
    int abs_d_y = abs(d_y);
    int inc_x = 0;
    int inc_y = 0;

    if (abs_d_x >= abs_d_y) {
        if (d_x > 0){  //->
            inc_x = 1;
        } else {  //<-
            inc_x = -1;
        }
    } else {
        if (d_y > 0){   //🡱
            inc_y = 1;
        } else {   //🡳
            inc_y = -1;
        }
    }

    ICell& next_cell = m_field->getCell(m_x + inc_x, m_y + inc_y);

    if (next_cell.getPassable() == false){  //проверка на проходимость след клетки
        return;
    }

    if (next_cell.topCreature()) {  //проверка есть ли существо на след клетке

        if (next_cell.topCreature()->getTypeCreature() == TPlayer) {
            toDamage(next_cell.topCreature());  //нанесение урона
            return;
        } else {
            return;
        }

    } else {//перемещение
        ICreature* myself = m_field->getCell(m_x, m_y).popCreature();
        m_x = m_x + inc_x;
        m_y = m_y + inc_y;
        next_cell.putCreature(myself);

        //логирование
        EventMove event(this, inc_x, inc_y);
        notify<EventMove>(event);

    }
}



TypeCreature CleverAlien::getTypeCreature() const {
    return TCleverAlien;
}

void CleverAlien::follow(Player *player) {
    m_player = player;
}

std::string CleverAlien::name() {
    return "Пришелец ";
}


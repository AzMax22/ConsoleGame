#include "HorizontalSkeleton.h"
#include "Player.h"
#include "Field.h"

HorizontalSkeleton::HorizontalSkeleton(): ICreature(){
    m_max_health = 50;
    m_health = 50;
    m_armor = 5;
    m_damage = 10;
    m_interval_steps = 20;
    m_time_last_step = 0;
    m_interval_steps = 15; //количество тактов между перемещения
    m_time_last_step = 0;
    m_interval_attacks = 30; //количество тактов между атаками
    m_time_last_attack = 0;
}

TypeGameObj HorizontalSkeleton::getTypeCreature() const {
    return THorizontalSkeleton;
}


void HorizontalSkeleton::update() {
    int  inc;

    if(m_patrollingRight) { //опр смещение обекта на inc
        inc = 1;
    } else {
        inc = -1;
    }

    ICell& next_cell = m_field->getCell(m_x+inc, m_y);

    if (next_cell.topCreature()) {  //проверка есть ли существо на след клетке
        if (next_cell.topCreature()->getTypeCreature() == TPlayer) {
            m_time_last_step = 0;//сброс задержки хода

            //нанесение урона
            if (m_time_last_attack != m_interval_attacks) {//задержка атаки
                m_time_last_attack++;
            } else {
                m_time_last_attack = 0;
                toDamage(next_cell.topCreature());
                return;
            }
        }
    }

    //перемещение(если надо)
    if (m_time_last_step != m_interval_steps) {//задержка хода
        m_time_last_step++;
    }else {
        m_time_last_step = 0;
        _move(next_cell, inc);
    }

}

bool HorizontalSkeleton::getPatrollingRight() {
    return m_patrollingRight;
}


std::string HorizontalSkeleton::name() {
    return "Скелет ";
}

void HorizontalSkeleton::_move(ICell &next_cell, int inc) {
    if (next_cell.getPassable() == false){  //проверка на проходимость след клетки
        m_patrollingRight = !m_patrollingRight; //разворот

        //логирование
        EventReversal event(this);
        notify<EventReversal>(event);
        return;
    }

    if (next_cell.topCreature()) {  //проверка есть ли существо на след клетке

        if (next_cell.topCreature()->getTypeCreature() == TPlayer) {
            //toDamage(next_cell.topCreature());  //нанесение урона
            //return;
        } else {
            m_patrollingRight = !m_patrollingRight; //разворот если сущ не игрок

            //логирование
            EventReversal event(this);
            notify<EventReversal>(event);
            return;
        }

    } else {//перемещение

        ICreature *myself = m_field->getCell(m_x, m_y).popCreature();
        m_x = m_x + inc;
        next_cell.putCreature(myself);

        //логирование
        EventMove event(this, inc, 0);
        notify<EventMove>(event);

    }

    return;
}

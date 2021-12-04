#include "VerticalScorpion.h"
#include "Field.h"

VerticalScorpion::VerticalScorpion() : ICreature() {
    m_max_health = 30;
    m_health = 30;
    m_armor = 5;
    m_damage = 20;
    m_step_duration = 20;
    m_time_last_step = 0;
}

void VerticalScorpion::update() {
    if (m_time_last_step != m_step_duration) {//задержка хода
        m_time_last_step++;
        return;
    }
    m_time_last_step = 0;

    int  inc;

    if(m_patrollingTop) { //опр смещение обекта на inc
        inc = -1;
    } else {
        inc = +1;
    }

    ICell& next_cell = m_field->getCell(m_x, m_y + inc);

    if (next_cell.getPassable() == false){  //проверка на проходимость след клетки
        m_patrollingTop = !m_patrollingTop; //разворот

        //логирование
        EventReversal event(this);
        notify<EventReversal>(event);
        return;
    }

    if (next_cell.topCreature()) {  //проверка есть ли существо на след клетке

        if (next_cell.topCreature()->getTypeCreature() == TPlayer) {
            toDamage(next_cell.topCreature());  //нанесение урона
            return;
        } else {
            m_patrollingTop = !m_patrollingTop; //разворот если сущ не игрок

            //логирование
            EventReversal event(this);
            notify<EventReversal>(event);
            return;
        }

    } else {//перемещение
        ICreature *myself = m_field->getCell(m_x, m_y).popCreature();
        m_y = m_y + inc;
        next_cell.putCreature(myself);

        EventMove event(this, 0, inc);
        notify<EventMove>(event);

    }

    return;
}

TypeCreature VerticalScorpion::getTypeCreature() const {
    return TVerticalScorpion;
}

bool VerticalScorpion::getPatrollingTop() {
    return m_patrollingTop;
}

std::string VerticalScorpion::name() {
    return "Скорпион ";
}


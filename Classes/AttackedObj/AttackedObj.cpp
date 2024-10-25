//
// Created by maxim on 04.12.2021.
//

#include "AttackedObj.h"


int AttackedObj::getCurrTimeViewAttacked() {
    return m_cur_time_view_attacked;
}

void AttackedObj::viewAttacked() {
    m_cur_time_view_attacked = m_time_view_attacked;
}

void AttackedObj::updateCurrTimeViewAttacked() {
    m_cur_time_view_attacked--;
}
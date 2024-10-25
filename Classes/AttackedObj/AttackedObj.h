//
// Created by maxim on 04.12.2021.
//

#ifndef CONSOLE_GAME_ATTACKEDOBJ_H
#define CONSOLE_GAME_ATTACKEDOBJ_H


class AttackedObj {
    int m_time_view_attacked = 5; //сколько тактов показывать атаку
    int m_cur_time_view_attacked = 0;  //сколько тактов осталось показывать атаку

public:
    int getCurrTimeViewAttacked();
    void viewAttacked();
    void updateCurrTimeViewAttacked();
};


#endif //CONSOLE_GAME_ATTACKEDOBJ_H

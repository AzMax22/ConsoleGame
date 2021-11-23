//
// Created by maxim on 23.11.2021.
//

#ifndef CONSOLE_GAME_CONTROLER_H
#define CONSOLE_GAME_CONTROLER_H

#include "Game.h"

class Controler {
    Game& m_game;
public:
    Controler(Game& game);

    //отрисовка
    void update();

    ~Controler();
};


#endif //CONSOLE_GAME_CONTROLER_H

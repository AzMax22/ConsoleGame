//
// Created by maxim on 23.11.2021.
//

#ifndef CONSOLE_GAME_CONTROLER_H
#define CONSOLE_GAME_CONTROLER_H

#include "Game.h"

template<class TGame>
class Controler {
    TGame& m_game;
public:
    Controler(TGame& game);

    //отрисовка
    void update();
    void waitingInput();

    ~Controler();
};

#include "Controler.inl"
#endif //CONSOLE_GAME_CONTROLER_H

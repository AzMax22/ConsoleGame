//
// Created by maxim on 23.11.2021.
//

#include "Controler.h"
#include "iostream"
#include "SetKeys.h"
#include "ncurses.h"

Controler::Controler(Game &game) : m_game(game){


}

void Controler::update() {

    wchar_t a;
    a = std::wcin.get();

    if (SetKeys::keyLeft.find(a) != std::string::npos){
        m_game.movePlayer(-1, 0);
    }
    if (SetKeys::keyRight.find(a) != std::string::npos){
        m_game.movePlayer(1, 0);
    }
    if (SetKeys::keyUp.find(a) != std::string::npos){
        m_game.movePlayer(0, -1);
    }
    if (SetKeys::keyDown.find(a) != std::string::npos){
        m_game.movePlayer(0, 1);
    }

}

Controler::~Controler() {

}

#include "iostream"
#include "SetKeys.h"


template<class TGame>
Controler<TGame>::Controler(TGame &game) : m_game(game){

}

template<class TGame>
void Controler<TGame>::update() {

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

    a = std::wcin.get();

}

template<class TGame>
Controler<TGame>::~Controler() {

}

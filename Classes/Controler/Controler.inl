#include "iostream"
#include "SetKeys.h"
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>


template<class TGame>
Controler<TGame>::Controler(TGame &game) : m_game(game){
    noecho(); //отключает эхо
    keypad(stdscr, TRUE); // позволяет использовать стрелки
    nodelay(stdscr, TRUE); //отключение ожидания ввода getch
}

template<class TGame>
void Controler<TGame>::update() {


    wint_t ch ;
    int err;
    err = get_wch(&ch);

    if (find(SetKeys::keyUp.begin(),SetKeys::keyUp.end(),ch) != SetKeys::keyUp.end()){
        m_game.movePlayer(0, -1);
    }
    if (find(SetKeys::keyDown.begin(),SetKeys::keyDown.end(),ch) != SetKeys::keyDown.end()){
        m_game.movePlayer(0, 1);
    }
    if (find(SetKeys::keyLeft.begin(),SetKeys::keyLeft.end(),ch) != SetKeys::keyLeft.end()){
        m_game.movePlayer(-1, 0);
    }
    if (find(SetKeys::keyRight.begin(),SetKeys::keyRight.end(),ch) != SetKeys::keyRight.end()){
        m_game.movePlayer(1, 0);
    }

    flushinp();//сброс буфера ввода
}

template<class TGame>
Controler<TGame>::~Controler() {

}

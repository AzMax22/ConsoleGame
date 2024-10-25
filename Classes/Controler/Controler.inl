#include "iostream"
#include "SetKeys.h"
#include "Controler.h"

#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>
#include "ViewGame.h"



template<class TGame>
Controler<TGame>::Controler(TGame &game) : m_game(game){
    curs_set(0); //делает курсор невидимым
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
    if (find(SetKeys::keyExit.begin(),SetKeys::keyExit.end(),ch) != SetKeys::keyExit.end()){
        m_game.gameExit();
    }
    if (find(SetKeys::keyAttack.begin(),SetKeys::keyAttack.end(),ch) != SetKeys::keyAttack.end()){
        m_game.attackPlayer();
    }
    if (find(SetKeys::keySave.begin(),SetKeys::keySave.end(),ch) != SetKeys::keySave.end()) {
        menuSaveGame();
    }
    if (find(SetKeys::keyLoadSave.begin(),SetKeys::keyLoadSave.end(),ch) != SetKeys::keyLoadSave.end()) {
        menuLoadSaveGame();
    }

    flushinp();//сброс буфера ввода
}

template<class TGame>
Controler<TGame>::~Controler() {

}

template<class TGame>
void Controler<TGame>::waitingInput() {
    nodelay(stdscr, FALSE);
    wint_t ch ;
    get_wch(&ch);

}

template<class TGame>
void Controler<TGame>::menuSaveGame() {
    clear();

    echo();
    nodelay(stdscr, FALSE);
    curs_set(1); //видимость курсора

    addwstr(L"Сохранение игры, введите название сохранения:\n");
    char str[100];
    getstr(str);

    if (str[0] != '\0') {

        if (m_game.save(str)) {
            attron(COLOR_PAIR(Color_FGreen_BDef));
            printw("Игра успешно сохранена в файл ", str);

            attron(A_UNDERLINE);
            printw("%s.save\n", str);
            attroff(A_UNDERLINE);

            attroff(COLOR_PAIR(Color_FGreen_BDef));
        } else {
            attron(COLOR_PAIR(Color_FRed_BDef));

            printw("Невозможно сохранить игру (ошибка создания директории Save)\n");

            attroff(COLOR_PAIR(Color_FRed_BDef));
        }

        printw("Нажмите Enter чтобы продолжить.\n", str);
        getch();
    }



    curs_set(0);
    noecho(); //отключает эхо
    nodelay(stdscr, TRUE); //отключение ожидания ввода getch
}

template<class TGame>
void Controler<TGame>::menuLoadSaveGame() {
    clear();

    echo();
    nodelay(stdscr, FALSE);
    curs_set(1); //видимость курсора

    addwstr(L"Загрузка сохранения, введите название сохранения:\n");
    char str[100];
    getstr(str);

    if (str[0] != '\0') {
        if(!m_game.loadSave(str)){

            attron(COLOR_PAIR(Color_FRed_BDef));

            printw("Невозможно загрузить игру (некоректное сохранение)\n");

            attroff(COLOR_PAIR(Color_FRed_BDef));

            printw("Нажмите Enter чтобы продолжить.\n", str);

        }
    }
    getch();


    curs_set(0);
    noecho(); //отключает эхо
    nodelay(stdscr, TRUE); //отключение ожидания ввода getch
}



#include <iostream>

#include "ViewGame.h"
#include "Game.h"
#include "Controler.h"
#include "ncurses.h"

int main() {
    //локализация для юникода
    std::locale::global(std::locale("en_US.utf8"));

    //инициализация билиотеки ncures.h и задание нужного режима консоли
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    //отображение
    Game game;
    ViewGame  view(game);
    Controler controler(game);


    view.rendering(); //начальное отображние


    while (game.gameState() == RUN){
        controler.update();
        game.update();
        view.rendering();

        //usleep(200000*4);

    }

    //освобождение ресурсов ncurses
    endwin();
    //сбрасываем локаль , иначе будет утечка памяти
    std::locale::global(std::locale("C"));
    return 0;
}

#include <iostream>

#include "ViewGame.h"
#include "Game.h"
#include "Controler.h"

int main() {
    //локализация для юникода
    std::locale::global(std::locale("en_US.utf8"));


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


    //сбрасываем локаль , иначе будет утечка памяти
    std::locale::global(std::locale("C"));
    return 0;
}

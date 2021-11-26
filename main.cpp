#include <iostream>

#include "ViewGame.h"
#include "Game.h"
#include "Controler.h"
#include "GenerationLevel.h"

int main() {
    //локализация для юникода
    std::locale::global(std::locale("en_US.utf8"));

    using GenLevel = GenerationLevel<1>;
    GenLevel gen_level;



    using NewGame = Game<GenLevel>;

    NewGame game(gen_level);
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

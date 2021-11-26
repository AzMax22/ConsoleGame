#include <iostream>

#include "ViewGame.h"
#include "Game.h"
#include "Controler.h"
#include "GenerationLevel.h"
#include "RuleSetLocatedGameObj.h"

int main() {
    //локализация для юникода
    std::locale::global(std::locale("en_US.utf8"));

    const int level = 0;

    using GenLevel = GenerationLevel<level>;
    GenLevel gen_level;

    using RSetLocatedObj = RuleSetLocatedGameObj<level, 1>;
    RSetLocatedObj r_set_located;

    using NewGame = Game<GenLevel, RSetLocatedObj>;

    NewGame game(gen_level, r_set_located);
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

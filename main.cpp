#include <iostream>

#include "ViewGame.h"
#include "Game.h"
#include "Controler.h"
#include "GenerationLevel.h"
#include "RuleSetLocatedGameObj.h"
#include "RWinAndLose.h"
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>
#include "unistd.h"


int main() {
    //локализация для юникода
    std::locale::global(std::locale("en_US.utf8"));

    //инициализация билиотеки ncures.h и задание нужного режима консоли
    initscr();

    const int level = 1;

    using GenLevel = GenerationLevel<level>;
    GenLevel gen_level;

    using RSetLocatedObj = RuleSetLocatedGameObj<level, 1>;
    RSetLocatedObj r_set_located;

    using RWinAndLose = RWinAndLose<NoDamageMode>;
    RWinAndLose r_win_lose;

    using NewGame = Game<GenLevel, RSetLocatedObj, RWinAndLose>;

    NewGame game(gen_level, r_set_located, r_win_lose);
    ViewGame  view(game);
    Controler controler(game);

    view.rendering(); //начальное отображние

    while (game.gameState() == RUN){


        controler.update();
        game.update();
        view.rendering();

        usleep(20000);
    }


    //wchar_t a;
    //a = std::wcin.get();

    //освобождение ресурсов ncurses
    endwin();

    //сбрасываем локаль , иначе будет утечка памяти
    std::locale::global(std::locale("C"));
    return 0;
}

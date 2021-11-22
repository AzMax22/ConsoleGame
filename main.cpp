#include <iostream>

#include "HorizontalSkeleton.h"
#include "VerticalScorpion.h"
#include <unistd.h>
#include "Player.h"
#include "Items/Sword/Sword.h"
#include "Croissant.h"
#include "Shield.h"
#include "ViewField.h"
#include "ViewGame.h"
#include "Game.h"




int main() {
    //отображение
    Game game;
    ViewGame  view(game);

    char a;
    view.rendering(); //начальное отображние
    a = std::cin.get();
    int i = 0;


    while (( i < 25 ) and (game.gameState() == RUN)){

        game.update();
        view.rendering();


        a = std::cin.get();
        i +=1;

        //usleep(200000*4);

    }




    return 0;
}

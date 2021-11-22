#ifndef CONSOLE_GAME_VIEWGAME_H
#define CONSOLE_GAME_VIEWGAME_H

#include "Game.h"
#include "ViewField.h"

class ViewGame {
    Game& m_game;
    ViewField m_view_field;
public:
    ViewGame(Game& game);

    //отрисовка
    void rendering();

};


#endif //CONSOLE_GAME_VIEWGAME_H

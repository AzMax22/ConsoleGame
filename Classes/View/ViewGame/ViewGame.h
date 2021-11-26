#ifndef CONSOLE_GAME_VIEWGAME_H
#define CONSOLE_GAME_VIEWGAME_H

#include "Game.h"
#include "ViewField.h"

template<class TGame>
class ViewGame {
    TGame& m_game;
    ViewField m_view_field;
public:
    ViewGame(TGame& game);

    //отрисовка
    void rendering();

};

#include "ViewGame.inl"
#endif //CONSOLE_GAME_VIEWGAME_H

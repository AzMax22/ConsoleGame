#ifndef CONSOLE_GAME_VIEWGAME_H
#define CONSOLE_GAME_VIEWGAME_H

#include "Game.h"
#include "ViewField.h"

enum ColorText{
    Color_Default = 0,
    Color_FWhite_BCyan,
    Color_FWhite_BGreen,
    Color_FWhite_BRed,
    Color_FWhite_BBlack,
    Color_FBlue_BBlack,
    Color_FGreen_BBlack,
    Color_FCyan_BBlack,
    Color_FYellow_BBlack
};

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

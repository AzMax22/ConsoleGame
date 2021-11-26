#ifndef CONSOLE_GAME_RWINANDLOSE_H
#define CONSOLE_GAME_RWINANDLOSE_H

#include "Game.h"

enum modeGame{
    NormalMode,
    NoDamageMode
};


template<int number>
class RWinAndLose{
public:
    template<class TGame>
    bool win(TGame* game){
        ICell& cell_player = game->getField()->getCell(game->getPlayer()->getX(), game->getPlayer()->getY());

        if (cell_player.getTypeCell() == TEndCell){
            return true;
        } else
            return false;

    }

    template<class TGame>
    bool lose(TGame* game){
        if (game->getPlayer()->getAlive() == false){
            return true;
        } else {
            return false;
        }
    }
};


template<>
class RWinAndLose<NoDamageMode>{
public:
    template<class TGame>
    bool win(TGame* game){
        ICell& cell_player = game->getField()->getCell(game->getPlayer()->getX(), game->getPlayer()->getY());

        if (cell_player.getTypeCell() == TEndCell){
            return true;
        } else
            return false;

    }

    template<class TGame>
    bool lose(TGame* game){
        if (game->getPlayer()->getHealth() != game->getPlayer()->getMaxHealth()){
            return true;
        } else {
            return false;
        }
    }
};

#endif //CONSOLE_GAME_RWINANDLOSE_H

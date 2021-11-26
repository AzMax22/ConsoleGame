#ifndef CONSOLE_GAME_GAME_H
#define CONSOLE_GAME_GAME_H

#include "BuilderField.h"
#include "Field.h"
#include "unq_p.h"
#include "CleverAlien.h"
#include "FileLog.h"
#include "ConsoleLog.h"
#include "Event.h"
#include "Logger.h"
#include "StateGame.h"




template<class GenLevel, class RSetLocatedObj>
class Game : public GameObject{
    unq_p<Field> m_field;
    std::vector<unq_p<IAutonomy>> m_set_update_obj;
    unq_p<Logger> m_logger;
    unq_p<Player> m_player;
    StateGame state_game = RUN;

public:
    Game(GenLevel& genlevel, RSetLocatedObj& r_set_located);

    void update();
    StateGame gameState();

    Field* getField();
    Logger* getLogger();
    void movePlayer(int inc_x, int inc_y);

    std::string name() override;


    ~Game();
};



#include "Game.inl"
#endif //CONSOLE_GAME_GAME_H

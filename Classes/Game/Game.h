#ifndef CONSOLE_GAME_GAME_H
#define CONSOLE_GAME_GAME_H

#include "BuilderField.h"
#include "Field.h"
#include "unq_p.h"
#include "CleverAlien.h"
#include "Logger.h"
#include "FileLog.h"
#include "ConsoleLog.h"
#include "Event.h"

enum StateGame{
    RUN,
    WIN,
    LOSE
};

class Game : public GameObject{
    unq_p<Field> m_field;
    unq_p<Player> m_player ;
    unq_p<CleverAlien> m_alien;
    unq_p<Logger> m_logger;
    StateGame state_game = RUN;

public:
    Game();

    void update();
    StateGame gameState();

    Field* getField();
    Logger* getLogger();
    void movePlayer(int inc_x, int inc_y);

    std::string name() override;


    ~Game();
};


#endif //CONSOLE_GAME_GAME_H

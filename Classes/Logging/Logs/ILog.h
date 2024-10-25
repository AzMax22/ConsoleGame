#ifndef CONSOLE_GAME_ILOG_H
#define CONSOLE_GAME_ILOG_H

#include "ostream"

class ILog{
public:
    virtual std::ostream& steam() = 0;
    virtual void update() ;
};

#endif //CONSOLE_GAME_ILOG_H

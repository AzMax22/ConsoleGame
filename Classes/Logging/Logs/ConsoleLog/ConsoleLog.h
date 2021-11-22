//
// Created by maxim on 17.11.2021.
//

#ifndef CONSOLE_GAME_CONSOLELOG_H
#define CONSOLE_GAME_CONSOLELOG_H

#include "ILog.h"
#include "sstream"

class ConsoleLog : public ILog {
    std::ostringstream m_string;
public:
    ConsoleLog();

    std::ostream & steam() override;

    void update() override;
};


#endif //CONSOLE_GAME_CONSOLELOG_H

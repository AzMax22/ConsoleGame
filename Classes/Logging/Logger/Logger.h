#ifndef CONSOLE_GAME_LOGGER_H
#define CONSOLE_GAME_LOGGER_H


#include "unq_p.h"
#include <fstream>
#include <string>
#include <vector>
#include "ILog.h"
#include "GameObject.h"
#include "Event.h"
#include "unq_p.h"

class Observable;

class Logger{
    std::vector<unq_p<ILog>> logs;
public:
    Logger(unq_p<ILog> some_steam);

    void addLog(unq_p<ILog> some_steam);
    void addObservable(Observable* some_obsle);
    void update();

    void processNotification(EventMove& event);
    void processNotification(EventReversal& event);
    void processNotification(EventChangeHealth& event);
    void processNotification(EventChangeArmor& event);
    void processNotification(EventChangeDamage& event);
    void processNotification(EventToAttack& event);
    void processNotification(EventSetLocation& event);
    void processNotification(EventDeath& event);
    void processNotification(EventAffect& event);
};





#endif //CONSOLE_GAME_LOGGER_H

#ifndef CONSOLE_GAME_LOGGER_H
#define CONSOLE_GAME_LOGGER_H


#include "unq_p.h"
#include <fstream>
#include <string>
#include <vector>
#include "ILog.h"
#include "Event.h"
#include "unq_p.h"
#include "StateGame.h"



class Observable;


class Logger{
    std::vector<unq_p<ILog>> logs;
    //bool something_happened = false;
public:
    Logger(unq_p<ILog> some_steam);

    void addLog(unq_p<ILog> some_steam);
    void addObservable(Observable* some_obsle);
    void update();

    //void somethingHappened();

    void processNotification(EventMove& event);
    void processNotification(EventReversal& event);
    void processNotification(EventChangeHealth& event);
    void processNotification(EventChangeArmor& event);
    void processNotification(EventChangeDamage& event);
    void processNotification(EventToAttack& event);
    void processNotification(EventSetLocation& event);
    void processNotification(EventDeath& event);
    void processNotification(EventAffect& event);
    void processNotification(EventChangeMaxHealth& event);

    template<class TGame>
    void processNotification(EventEndGame& event);
};





template<class TGame>
void Logger::processNotification(EventEndGame &event) {
    auto &obj = dynamic_cast<TGame&>(event.getObjEvent());

    if (obj.gameState() == WIN) {
        for (auto &&some_log: logs) {
            some_log->steam() << "Игрок победил" << std::endl;
        }
    }else {
        for (auto &&some_log: logs) {
            some_log->steam() << "Игрок проиграл" << std::endl;
        }
    }

    for (auto &&some_log: logs) {
        some_log->steam() << "Конец Игры" << std::endl;
    }

}


#endif //CONSOLE_GAME_LOGGER_H

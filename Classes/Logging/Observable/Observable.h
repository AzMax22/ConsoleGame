#ifndef CONSOLE_GAME_OBSERVABLE_H
#define CONSOLE_GAME_OBSERVABLE_H


#include <vector>
#include <string>
#include "Logger.h"
#include "GameObject.h"

class Observable {
private:
    Logger* m_logger = nullptr; //нужны ли умные указатели ?
public:
    void bindWithLogger(Logger* logger);

    template<class T>
    void notify(T& event);
};



template<class T>
void Observable::notify(T& event) {
    if (m_logger == nullptr){
        return;
    }

    m_logger->processNotification(event);
}


#endif //CONSOLE_GAME_OBSERVABLE_H

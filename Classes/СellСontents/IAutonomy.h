#ifndef CONSOLE_GAME_IAUTONOMY_H
#define CONSOLE_GAME_IAUTONOMY_H

#include "Observable.h"

//интерфейс классов котрые имею "автономное поведение" , независимое от игрока(человека)
class IAutonomy : public Observable {
protected:
    bool m_alive = true;
public:
    virtual  void update() = 0; //обновление ("реализация поведения")
    virtual void death() = 0; //удаление обьекта
    bool getAlive();
    virtual ~IAutonomy() = default;
};




#endif //CONSOLE_GAME_IAUTONOMY_H



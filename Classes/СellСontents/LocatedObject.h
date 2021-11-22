//
// Created by maxim on 23.11.2021.
//

#ifndef CONSOLE_GAME_LOCATEDOBJECT_H
#define CONSOLE_GAME_LOCATEDOBJECT_H

#include "GameObject.h"

class LocatedObject: public GameObject{
public:
    using GameObject::GameObject;
    virtual int getX() = 0;
    virtual int getY() = 0;
};


#endif //CONSOLE_GAME_LOCATEDOBJECT_H

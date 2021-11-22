#ifndef CONSOLE_GAME_GAMEOBJECT_H
#define CONSOLE_GAME_GAMEOBJECT_H

#include "string"

class GameObject {
protected:
    static int m_count_obj;
    int m_id;

public:
    GameObject();  // увеличиваем значение идентификатора для следующего объекта

    virtual std::string name() = 0;

    int getID() ;

    friend std::ostream& operator<< (std::ostream &out,  GameObject& obj);
};



#endif //CONSOLE_GAME_GAMEOBJECT_H

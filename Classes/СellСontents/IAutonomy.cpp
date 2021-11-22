#include "IAutonomy.h"

//Реализация по умолчанию

bool IAutonomy::getAlive() {
    return  m_alive;
}

void IAutonomy::death(){
    m_alive = false;
};

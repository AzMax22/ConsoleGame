#include "GameObject.h"

int GameObject::m_count_obj = 0;

GameObject::GameObject() {
    m_id = m_count_obj++;
}

int GameObject::getID() {
    return m_id;
}


std::ostream &operator<<(std::ostream &out, GameObject &obj) {
    out << obj.name() + "[" + std::to_string(obj.getID()) + "] ";
    return out;
}



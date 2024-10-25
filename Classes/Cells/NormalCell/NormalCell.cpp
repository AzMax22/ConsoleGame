#include "NormalCell.h"
#include <exception>

NormalCell::NormalCell(bool passable) {
    m_passable = passable;
}

void NormalCell::putItem(unq_p<IItem> item) {
    if (m_passable){
        if (m_item == nullptr){
            m_item = std::move(item);
        } else {throw std::runtime_error("Cell already have item");}
    }else {throw std::runtime_error("Cell is not passable");}
}

IItem* NormalCell::topItem(){
    return m_item.get();
}

unq_p<IItem> NormalCell::popItem(){
    return std::move(m_item);
}


void NormalCell::putCreature(ICreature* creature){
    if (m_passable){
        if (m_creature == nullptr){
            m_creature = creature;
        } else {throw "Cell already have creature";}
    }else {throw "Cell is not passable";}
}

ICreature* NormalCell::topCreature() {
    return m_creature;
}

ICreature* NormalCell::popCreature() {
    auto tmp_p = m_creature;
    m_creature = nullptr;
    return tmp_p;
}

TypeCell NormalCell::getTypeCell() const {
    if (m_passable) {
        return TNormalCell;
    } else {
        return TImpassableCell;
    }
}

unq_p<ICell> NormalCell::clone() {
    return _universal_clone<NormalCell>();
}

bool NormalCell::getPassable() {
    return m_passable;
}





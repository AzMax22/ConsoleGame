#include "IItem.h"
#include "Field.h"

void IItem::setLocation(int x, int y, unq_p<IItem> myself, Field *field) {
    if (field->getCell(x, y).topItem() == nullptr){ //проверка на пустоту клетки
        m_x = x;
        m_y = y;
        m_field = field;
        m_field->getCell(m_x, m_y).putItem(std::move(myself));

        EventSetLocation event(this);
        notify<EventSetLocation>(event);

    }else {throw std::runtime_error("Cell have  already  ICreature");}

}

void IItem::deleteItem() {
    m_field->getCell(m_x, m_y).popItem().reset();

    EventDeath event(this);
    notify<EventDeath>(event);
}

int IItem::getX() {
    return m_x;
}

int IItem::getY() {
    return m_y;
}

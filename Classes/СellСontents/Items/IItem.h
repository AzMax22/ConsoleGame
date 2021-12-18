#ifndef CONSOLE_GAME_IITEM_H
#define CONSOLE_GAME_IITEM_H

#include "unq_p.h"
#include "ICreature.h"





class IItem : public Observable, public LocatedObject {
protected:
    int m_x, m_y; //координаты на поле
    Field* m_field; //указатель на поле
public:
    virtual void affect(ICreature* creature) = 0;

    void setLocation(int x, int y,unq_p<IItem> myself ,Field* field) ; //размещение обекта на поле

    virtual unq_p<IItem> clone() = 0;

    virtual TypeGameObj getTypeItem() const = 0 ;

    int getX() override;
    int getY() override;

    virtual void deleteItem();

    ~IItem()  = default;

};

#endif //CONSOLE_GAME_IITEM_H

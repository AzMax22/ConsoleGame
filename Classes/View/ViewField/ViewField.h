#ifndef CONSOLE_GAME_VIEWFIELD_H
#define CONSOLE_GAME_VIEWFIELD_H

#include  "unq_p.h"
#include "Field.h"

class ViewField {
    Field* m_field;
public:
    ViewField(Field* field);

    //отрисовка
    void rendering();

    ~ViewField();
};


#endif //CONSOLE_GAME_VIEWFIELD_H

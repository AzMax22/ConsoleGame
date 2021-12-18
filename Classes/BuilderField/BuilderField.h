#ifndef CONSOLE_GAME_BUILDERFIELD_H
#define CONSOLE_GAME_BUILDERFIELD_H

#include "Field.h"
#include "unq_p.h"
#include "Player.h"

class BuilderField  {
    unq_p<Field> m_field = nullptr;


public:
    BuilderField()=default;
    void createEmptyField(int level, int width, int height) ; //выделение памяти для поля
    void buildEndCell(int x, int y) ; //поставить на поле конечную клетку
    void buildEndCell() ; //поставить в случайное место на поле конечную клетку
    void buildImpassableCell(int x, int y) ; // поставить на поле непроходимую клетку
    void buildWall(int x_1, int y_1, int x_2, int y_2); //построить стену
    void buildRandomImpassableCells(int percentage) ; // Поставить на поле какойто процент непроход кл
    unq_p<Field> getField() ; //Получить поле
};




#endif //CONSOLE_GAME_BUILDERFIELD_H

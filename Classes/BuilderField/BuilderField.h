#ifndef CONSOLE_GAME_BUILDERFIELD_H
#define CONSOLE_GAME_BUILDERFIELD_H

#include "Field.h"
#include "unq_p.h"
#include "Player.h"

class BuilderField  {
    unq_p<Field> m_field = nullptr;

    //проверяет есть ли рядом клетка типа t_cell
    bool _checkXY(int x, int y, TypeCell t_cell);
    bool _checkNear(int x, int y, TypeCell t_cell);
public:
    BuilderField()=default;
    void createEmptyField(int width, int height) ; //выделение памяти для поля
    unq_p<Player> buildStartCell(int x, int y) ; //поставить на поле началную клетку
    unq_p<Player> buildStartCell() ; //поставить в случайное место на поле началную клетку
    void buildEndCell(int x, int y) ; //поставить на поле конечную клетку
    void buildEndCell() ; //поставить в случайное место на поле конечную клетку
    void buildImpassableCell(int x, int y) ; // поставить на поле непроходимую клетку
    void buildRandomImpassableCells(int percentage) ; // Поставить на поле какойто процент непроход кл
    unq_p<Field> getField() ; //Получить поле
};




#endif //CONSOLE_GAME_BUILDERFIELD_H

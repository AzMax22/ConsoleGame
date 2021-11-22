#ifndef CONSOLE_GAME_FIELD_H
#define CONSOLE_GAME_FIELD_H

#include "ICell.h"
#include <memory>
#include "unq_p.h"


class BuilderField;//странно, но нужно //а точно для обявления дуж класссом

class Field {
    int m_height, m_width; //значение рабочего поля без границы
    arr2d_unq<ICell> arr_cells; //arr2d_unq - двумерный массив умн. указателей

    Field(int width,int height);  //конструктор

    //выделяет массив указазтелей для arr_cells
    arr2d_unq<ICell> _init_arr_cells(int width, int height);
public:

    //конструктор копирования
    Field(Field& other_field);

    //оператор копирования
    Field& operator= (Field& other_field) noexcept;

    //конструктор перемещения
    Field(Field&& other_field) noexcept;

    //оператор перемещения
    Field& operator= (Field&& other_field) noexcept;

    int getHeight();
    int getWidth();
    ICell& getCell(int x, int y);

    friend BuilderField;//чтобы строитель мог построить обьект
};


#endif //CONSOLE_GAME_FIELD_H

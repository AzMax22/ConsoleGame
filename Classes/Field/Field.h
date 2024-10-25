#ifndef CONSOLE_GAME_FIELD_H
#define CONSOLE_GAME_FIELD_H

#include "ICell.h"
#include <memory>
#include "unq_p.h"
#include <sstream>
#include <vector>

class BuilderField;//странно, но нужно //а точно для обявления дуж класссом

class Field {
    int m_level;
    int m_height, m_width; //значение рабочего поля без границы
    arr2d_unq<ICell> arr_cells; //arr2d_unq - двумерный массив умн. указателей
    std::vector<IItem*> m_set_items;

    Field(int level, int width,int height);  //конструктор

    //выделяет массив указазтелей для arr_cells
    arr2d_unq<ICell> _init_arr_cells(int width, int height);

    bool _checkXY(int x, int y, TypeCell t_cell);
    bool _checkNear(int x, int y, TypeCell t_cell);
public:
    void buildStartCell(int x, int y);

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
    void addItemInVec(IItem * item);
    void removeItemFromVec(IItem * item);

    std::string save();
    void deleteItems();

    friend BuilderField;//чтобы строитель мог построить обьект
};


#endif //CONSOLE_GAME_FIELD_H

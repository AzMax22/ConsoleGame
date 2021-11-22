#include "Field.h"
#include "StartCell.h"
#include "stdexcept"
#include "ICreature.h"

//конструктор
Field::Field (int width,int height)
: m_height(height-2), m_width(width-2)
{
    arr_cells = _init_arr_cells( width, height);
}

//конструктор копирования
Field::Field(Field &other_field) {
    *this = other_field;

}

//оператор копирования
Field& Field::operator= (Field &other_field) noexcept {
    if (this == &other_field){
        return *this;
    }

    m_width = other_field.m_width;
    m_height = other_field.m_height;

    arr_cells.reset();//удаление массива
    arr_cells = _init_arr_cells(m_width+2, m_height+2);// выделение памяти

    IItem* tmp_item;

    for (int x = 0; x < m_width+2; x++){
        for (int y = 0; y < m_height+2; y++){
            arr_cells[x][y] = other_field.arr_cells[x][y]->clone();
            tmp_item = other_field.getCell(x, y).topItem();

            if(tmp_item != nullptr){
                unq_p<IItem> new_item = tmp_item->clone();
                new_item->setLocation(tmp_item->getX(), tmp_item->getY(),std::move(new_item), this);
            }

        }
    }


    return *this;
}


//конструктор перемещения
Field::Field(Field &&other_field) noexcept {
    *this = std::move(other_field);
}

//оператор перемещения
Field& Field::operator= (Field &&other_field) noexcept {
    if (this == &other_field){
        return *this;
    }

    m_width = other_field.m_width;
    m_height = other_field.m_height;
    arr_cells = std::move(other_field.arr_cells);

    return *this;
}


int Field::getHeight() {
    return m_height;
}

int Field::getWidth() {
    return m_width;
}

ICell& Field::getCell(int x, int y) {
    return  *(arr_cells[x][y]);
}

arr2d_unq<ICell> Field::_init_arr_cells(int width, int height) {
    auto tmp_arr_cells = std::make_unique< arr_unq<ICell>[] > (width); // *** = new (**)[]

    for(int i = 0; i < width; i++){
        tmp_arr_cells[i] = std::make_unique< unq_p<ICell>[] >(height); //** = new (*)[]
    }

    return tmp_arr_cells;
}


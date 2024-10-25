#include "Field.h"
#include "StartCell.h"
#include "stdexcept"
#include "ICreature.h"
#include "ncursesw/ncurses.h"
//конструктор
Field::Field (int level, int width,int height)
: m_level(level),m_height(height-2), m_width(width-2)
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

void Field::buildStartCell(int x, int y) {
    if (arr_cells[x][y]->getPassable()) {

        if (!_checkNear(x,y,TEndCell)){
            arr_cells[x][y] = std::make_unique<StartCell>();
        } else {throw std::runtime_error("Error set player on field: Near EndCell");}

    } else {throw std::runtime_error("Error set player on field: Cell is impassable");}
}

bool Field::_checkNear(int x, int y, TypeCell t_cell) {
    if(_checkXY(x-1, y, t_cell) || _checkXY(x+1, y, t_cell) ||
       _checkXY(x, y-1, t_cell) || _checkXY(x, y+1, t_cell) ||
       _checkXY(x-1, y-1, t_cell) || _checkXY(x+1, y-1, t_cell) ||
       _checkXY(x-1, y+1, t_cell) || _checkXY(x+1, y+1, t_cell)){

        return true;
    } else {
        return false;
    }
}

bool Field::_checkXY(int x, int y, TypeCell t_cell) {
    if( (arr_cells[x][y] != nullptr)) {
        if (arr_cells[x][y]->getTypeCell() == t_cell){
            return true;
        }
    }
    return false;
}

std::string Field::save() {
    std::ostringstream res;

    res << m_level << "\n"; //интервал между регеном
    res << m_set_items.size() << "\n";
    for (IItem* item : m_set_items) {
        res << item->save() << "\n";
    }

    return res.str();
}

void Field::addItemInVec(IItem *item) {
    m_set_items.push_back(item);
}

void Field::removeItemFromVec(IItem *item) {

    for(int i = 0; i < m_set_items.size(); i++) {
        if (m_set_items[i] == item) {
            m_set_items.erase(m_set_items.begin() + i);
        }
    }
}

void Field::deleteItems() {
    for(int i = 0; i < m_set_items.size(); i++) {
        IItem* item = m_set_items.back();
        arr_cells[item->getX()][item->getY()]->popItem().reset();
        m_set_items.pop_back();
    }
}



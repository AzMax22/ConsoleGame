#include "BuilderField.h"
#include "StartCell.h"
#include "EndCell.h"
#include <random>
#include "My_Exception.h"


void BuilderField::createEmptyField(int width, int height)  {
    m_field = unq_p<Field>(new Field(width+2, height+2)); //+2 для рамки поля

    int x = 0, y = 0;

    //верхняяя стена
    for (x = 0; x < width+2; x++){
        m_field->arr_cells[x][y] =  std::make_unique<NormalCell>(false);
    }


    //правая стена
    x -= 1;
    for (y = 0 ; y < height+2; y++){
        m_field->arr_cells[x][y] =  std::make_unique<NormalCell>(false);
    }

    //левая стена
    x = 0;
    for (y = 0 ; y < height+2; y++){
        m_field->arr_cells[x][y] =  std::make_unique<NormalCell>(false);
    }

    //Нижняя стена
    y -=1;
    for (x = 0 ; x < width+2; x++){
        m_field->arr_cells[x][y] =  std::make_unique<NormalCell>(false);
    }
}

unq_p<Player> BuilderField::buildStartCell(int x, int y) {
    if (m_field->arr_cells[x][y] == nullptr) {

        if (!_checkNear(x,y,TEndCell)){
            m_field->arr_cells[x][y] = std::make_unique<StartCell>();
            auto player = std::make_unique<Player>(); //создание игрока
            player->setLocation(x, y, m_field.get());
            return std::move(player);
        } else {throw near_end_cell;}

    } else {throw cell_occupied;}
}

void BuilderField::buildEndCell(int x, int y) {
    if (m_field->arr_cells[x][y] == nullptr) {

        if (!_checkNear(x,y,TStartCell)) {
            m_field->arr_cells[x][y] = std::make_unique<EndCell>();
        } else {throw near_start_cell;}

    } else {throw cell_occupied;}
}

void BuilderField::buildImpassableCell(int x, int y) {
    if (m_field->arr_cells[x][y] == nullptr) {
        m_field->arr_cells[x][y] = std::make_unique<NormalCell>(false);
    } else {throw cell_occupied;}
}



void BuilderField::buildRandomImpassableCells(int percentage) {
    int amount_impass_cells = (int)(m_field->m_width * m_field->m_height * percentage / 100);

    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> rand_x(1,m_field->m_width);
    std::uniform_int_distribution<> rand_y(1,m_field->m_height);

    int x,y;

    for (int i = 0; i < amount_impass_cells; i++){
        x = rand_x(gen);
        y = rand_y(gen);

        try{
            this->buildImpassableCell(x, y);
        } catch (My_Exception& e){
            if (e == cell_occupied) {i-=1;}
        }
    }

}


unq_p<Field> BuilderField::getField() {
    for (int x = 1; x <= m_field->m_width; x++ ){
        for (int y = 1; y <= m_field->m_height; y++){
            if (m_field->arr_cells[x][y] == nullptr){
                m_field->arr_cells[x][y] = std::make_unique<NormalCell>();
            }
        }
    }
    return  std::move(m_field);
}

bool BuilderField::_checkNear(int x, int y, TypeCell t_cell) {
    if(_checkXY(x-1, y, t_cell) || _checkXY(x+1, y, t_cell) ||
            _checkXY(x, y-1, t_cell) || _checkXY(x, y+1, t_cell) ||
            _checkXY(x-1, y-1, t_cell) || _checkXY(x+1, y-1, t_cell) ||
            _checkXY(x-1, y+1, t_cell) || _checkXY(x+1, y+1, t_cell)){

        return true;
    } else {
        return false;
    }
}

bool BuilderField::_checkXY(int x, int y, TypeCell t_cell) {
    if( (m_field->arr_cells[x][y] != nullptr)) {
        if (m_field->arr_cells[x][y]->getTypeCell() == t_cell){
            return true;
        }
    }
    return false;
}

unq_p<Player> BuilderField::buildStartCell() {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> rand_x(1,m_field->m_width);
    std::uniform_int_distribution<> rand_y(1,m_field->m_height);

    int i = 0;
    unq_p<Player> player;
    while (i == 0) {
        try {
            i += 1;
            player = this->buildStartCell(rand_x(gen), rand_y(gen));
        } catch (My_Exception &e) {i -= 1;}
    }
    return std::move(player);
}

void BuilderField::buildEndCell() {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> rand_x(1,m_field->m_width);
    std::uniform_int_distribution<> rand_y(1,m_field->m_height);

    int i = 0;
    while (i == 0) {
        try {
            i += 1;
            this->buildEndCell(rand_x(gen), rand_y(gen));
        } catch (My_Exception &e) {i -= 1;}
    }
}



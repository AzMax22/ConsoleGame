#include "BuilderField.h"
#include "StartCell.h"
#include "EndCell.h"
#include <random>
#include "My_Exception.h"


void BuilderField::createEmptyField(int level, int width, int height)  {
    m_field = unq_p<Field>(new Field(level, width+2, height+2)); //+2 для рамки поля

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



void BuilderField::buildEndCell(int x, int y) {
    if (m_field->arr_cells[x][y] == nullptr) {

        m_field->arr_cells[x][y] = std::make_unique<EndCell>();

    } else {throw cell_occupied;}
}

void BuilderField::buildImpassableCell(int x, int y) {
    if (m_field->arr_cells[x][y] == nullptr) {
        m_field->arr_cells[x][y] = std::make_unique<NormalCell>(false);
    } else {
        if (m_field->arr_cells[x][y]->getPassable() == true) {
            throw cell_occupied;
        }
    }
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

void BuilderField::buildWall(int x_1, int y_1, int x_2, int y_2) {
    for (int i_x = x_1; i_x <= x_2; i_x++) {
        for (int i_y = y_1; i_y <= y_2; i_y++) {
            buildImpassableCell(i_x,i_y);
        }
    }
}



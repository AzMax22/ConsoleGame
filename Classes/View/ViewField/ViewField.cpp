#include "ViewField.h"
#include "ViewCell.h"
#include "iostream"
#include "Console.h"
#include <ncursesw/ncurses.h>

ViewField::ViewField(Field* field) {
    m_field = field;
}

void ViewField::rendering() {
    ViewCell view_cell;


    for (int y = 0; y < m_field->getHeight()+2; y++) {
        for (int x = 0; x < m_field->getWidth()+2; x++) {
            move(y, 2*x);
            view_cell.setModel(m_field->getCell(x, y));
            view_cell.draw();
        }
    }

}

ViewField::~ViewField() {

}

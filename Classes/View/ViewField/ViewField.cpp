#include "ViewField.h"
#include "ViewCell.h"
#include "iostream"
#include "Console.h"

ViewField::ViewField(Field* field) {
    m_field = field;
    g_console.visibleCursor(false);
    g_console.clearScreen();
}

void ViewField::rendering() {
    ViewCell view_cell;
    g_console.clearScreen(); // if not debag delet
    g_console.cursorToHome();

    for (int y = 0; y < m_field->getHeight()+2; y++) {
        for (int x = 0; x < m_field->getWidth()+2; x++) {

            view_cell.setModel(m_field->getCell(x, y));
            view_cell.draw();
        }
        std::wcout << std::endl;
    }
}

ViewField::~ViewField() {
    g_console.clearScreen();
    g_console.visibleCursor(true);
}

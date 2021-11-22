#include "Console.h"
#include "iostream"

Console g_console; //глобальная переменная


void Console::cursorToHome(){  //возвращает курсор в левй верхний угол , на коорд. (1, 1)
    std::wcout << ESC"[H" ;
}

void Console::clearScreen(){  //Очищает экран и перемещает курсор в его верхний левый угол.
    cursorToHome();
    std::wcout << ESC"[J" ;
}

void Console::moveCursor(int x, int y)	{ //перемещает курсор на координаты x , y
    std::wcout << ESC"["<< x << ";" << y <<"H";
}

void Console::visibleCursor(bool visible) { // видимость курсора
    if (visible){
        std::wcout <<ESC "[?25h";
    } else {
        std::wcout << ESC "[?25l";
    }
}

void  Console::resetTextColor() {
    std::wcout << ESC "[0m";
}

void Console::setTextAttrib(int attrib) {
    std::wcout << ESC "["<< attrib <<"m"  ;
}

void Console::toLeftCursor(int inc ) {
    std::wcout << ESC "[" << inc*2 << "D";
}

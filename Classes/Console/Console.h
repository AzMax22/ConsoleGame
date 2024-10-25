#ifndef CONSOLE_GAME_CONSOLE_H
#define CONSOLE_GAME_CONSOLE_H

#define ESC "\033"

//Format text
#define RESET 		0 //отключение отрибутов
#define BRIGHT 		1 //жирный ,яркий
#define DIM			2 //бледный
#define UNDERSCORE	3 //курсив
#define BLINK		4 //подчеркнуто
#define REVERSE		5 //миграние
#define HIDDEN		6 //Мигание: Часто

//Foreground Colours (text)
#define F_BLACK 	30
#define F_RED		31
#define F_GREEN		32
#define F_YELLOW	33
#define F_BLUE		34
#define F_MAGENTA 	35
#define F_CYAN		36
#define F_WHITE		37

//Background Colours
#define B_BLACK 	40
#define B_RED		41
#define B_GREEN		42
#define B_YELLOW	44
#define B_BLUE		44
#define B_MAGENTA 	45
#define B_CYAN		46
#define B_WHITE		47



class Console{

public:
    void cursorToHome(); //возвращает курсор в левй верхний угол , на коорд. (1, 1)

    void clearScreen(); //Очищает экран и перемещает курсор в его верхний левый угол.

    void moveCursor(int x, int y);  //перемещает курсор на координаты x , y

    void visibleCursor(bool visible);  // видимость курсора

    void  resetTextColor(); // сброс атрибутов

    void setTextAttrib(int attrib); // установить атрибут

    void toLeftCursor(int inc = 1); //
};


extern Console g_console; //глобальная переменная


#endif //CONSOLE_GAME_CONSOLE_H

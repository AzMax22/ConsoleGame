#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>
#include "ViewGame.h"



template<class TGame>
ViewGame<TGame>::ViewGame(TGame &game) :m_game(game), m_view_field(m_game.getField()){
    curs_set(0); //делает курсор невидимым
    start_color();
    use_default_colors();

    init_pair(Color_FWhite_BCyan, COLOR_WHITE, COLOR_CYAN);
    init_pair(Color_FWhite_BGreen, COLOR_WHITE, COLOR_GREEN);
    init_pair(Color_FWhite_BRed, COLOR_WHITE, COLOR_RED);
    init_pair(Color_FBlue_BRed, COLOR_BLUE, COLOR_RED);
    init_pair(Color_FGreen_BRed, COLOR_BLUE, COLOR_RED);
    init_pair(Color_FWhite_BBlack, COLOR_WHITE, COLOR_BLACK);
    init_pair(Color_FBlue_BBlack, COLOR_BLUE, COLOR_BLACK);
    init_pair(Color_FGreen_BBlack, COLOR_GREEN, COLOR_BLACK);
    init_pair(Color_FCyan_BBlack, COLOR_CYAN, COLOR_BLACK);
    init_pair(Color_FYellow_BBlack, COLOR_YELLOW, COLOR_BLACK);
    init_pair(Color_FMagneta_BBlack, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(Color_FGreen_BDef, COLOR_GREEN, -1);
    init_pair(Color_FRed_BDef, COLOR_RED, -1);
    init_pair(Color_FRed_BBlack, COLOR_RED, COLOR_BLACK);

}

template<class TGame>
void ViewGame<TGame>::rendering() {
    erase();

    m_view_field.rendering();
    m_game.getLogger()->update();

    std:std::wstring  wstr;

    move(0,2*(m_game.getField()->getWidth() + 10));
    wstr = L"Здоровье: " + std::to_wstring(m_game.getPlayer()->getHealth()) + L"/" + std::to_wstring(m_game.getPlayer()->getMaxHealth());
    addwstr(wstr.c_str());

    move(2,2*(m_game.getField()->getWidth() + 10));
    wstr = L"Броня: " + std::to_wstring(m_game.getPlayer()->getArmor());
    addwstr(wstr.c_str());

    move(4,2*(m_game.getField()->getWidth() + 10));
    wstr = L"Урон: " + std::to_wstring(m_game.getPlayer()->getDamage());
    addwstr(wstr.c_str());

    move(6,2*(m_game.getField()->getWidth() + 10));
    wstr = L"Скорость движения: " + std::to_wstring(m_game.getPlayer()->getSpeedMove());
    addwstr(wstr.c_str());
}

template<class TGame>
void ViewGame<TGame>::endRengering() {
    erase();
    int height, width;
    int x,y;
    getmaxyx(stdscr, height,width);

    std::string file_name;
    ColorText color;

    if (m_game.gameState() == WIN) {
        file_name = "WIN.txt";
        color = Color_FGreen_BDef;
        x = width/2 - 30;
        y = height/2 - 5;
    }

    if(m_game.gameState() == LOSE){
        file_name = "LOSE.txt";
        color = Color_FRed_BDef;
        x = width/2 - 30;
        y = height/2 - 4;
    }



    attron(COLOR_PAIR(color));

    std::wstring line;
    int i = 0;

    std::wifstream f_text_win(file_name); // окрываем файл для чтения
    if (f_text_win.is_open())
    {
        while (getline(f_text_win, line))
        {
            move(y + i,x);
            addwstr(line.c_str());
            i++;
        }
    }

    f_text_win.close();     // закрываем файл
    attroff(COLOR_PAIR(color));

}

#include <ncursesw/ncurses.h>

template<class TGame>
ViewGame<TGame>::ViewGame(TGame &game) :m_game(game), m_view_field(m_game.getField()){
    curs_set(0); //делает курсор невидимым
    start_color();
    use_default_colors();

    init_pair(Color_FWhite_BCyan, COLOR_WHITE, COLOR_CYAN);
    init_pair(Color_FWhite_BGreen, COLOR_WHITE, COLOR_GREEN);
    init_pair(Color_FWhite_BRed, COLOR_WHITE, COLOR_RED);
    init_pair(Color_FWhite_BBlack, COLOR_WHITE, COLOR_BLACK);
    init_pair(Color_FBlue_BBlack, COLOR_BLUE, COLOR_BLACK);
    init_pair(Color_FGreen_BBlack, COLOR_GREEN, COLOR_BLACK);
    init_pair(Color_FCyan_BBlack, COLOR_CYAN, COLOR_BLACK);
    init_pair(Color_FYellow_BBlack, COLOR_YELLOW, COLOR_BLACK);

}

template<class TGame>
void ViewGame<TGame>::rendering() {
    m_view_field.rendering();
    //m_game.getLogger()->update(); //нужен для консольного логера, тк он записывает после отрисовки
}

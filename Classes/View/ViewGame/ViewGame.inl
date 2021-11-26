template<class TGame>
ViewGame<TGame>::ViewGame(TGame &game) :m_game(game), m_view_field(m_game.getField()){

}

template<class TGame>
void ViewGame<TGame>::rendering() {
    m_view_field.rendering();
    m_game.getLogger()->update(); //нужен для консольного логера, тк он записывает после отрисовки
}

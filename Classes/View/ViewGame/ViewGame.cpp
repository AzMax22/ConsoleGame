//
// Created by maxim on 22.11.2021.
//

#include "ViewGame.h"


ViewGame::ViewGame(Game &game) :m_game(game), m_view_field(m_game.getField()){

}

void ViewGame::rendering() {
    m_view_field.rendering();
    m_game.getLogger()->update(); //нужен для консольного логера, тк он записывает после отрисовки
}

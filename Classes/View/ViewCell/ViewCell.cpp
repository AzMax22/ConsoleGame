#include "ViewCell.h"
#include "iostream"
#include "ICreature.h"
#include "IItem.h"
#include "Console.h"
#include "HorizontalSkeleton.h"
#include "VerticalScorpion.h"
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>
#include "ViewGame.h"


void ViewCell::setModel(ICell &cell) {
 m_cell = &cell;
}

void ViewCell::draw() {
    int color_background = COLOR_BLACK;
    int color_foreground = COLOR_WHITE;
    ColorText color_pair;
    const wchar_t* wstr;

    switch (m_cell->getTypeCell()) {
        case TNormalCell:
            color_background = COLOR_BLACK;
            break;
        case TEndCell:
            color_background = COLOR_RED;
            break;
        case TStartCell:
            color_background = COLOR_GREEN;
            break;
        case TImpassableCell:
            color_background = COLOR_CYAN;
            break;
    }

    if (m_cell->getCurrTimeViewAttacked() != 0) {
        color_background = COLOR_RED;
        m_cell->updateCurrTimeViewAttacked();
    }



    if (m_cell->topItem()) { //проверка на nullptr
        switch (m_cell->topItem()->getTypeItem()) {
            case TSword: {
                color_foreground = COLOR_BLUE;
                wstr = L"🗡 ";
                break;
            }

            case TCroissant: {
                color_foreground = COLOR_GREEN;
                wstr = L"✙ ";
                break;
            }

            case TShield: {
                color_foreground = COLOR_CYAN;
                wstr = L"⛨ ";
                break;
            }


        }
        color_pair = _convertToColorPair(color_foreground, color_background);
        attron(COLOR_PAIR(color_pair));
        addwstr(wstr);
        attroff(COLOR_PAIR(color_pair));
        return;
    }




    if (m_cell->topCreature()) { //проверка на nullptr
        switch (m_cell->topCreature()->getTypeCreature()) {
            case THorizontalSkeleton: {
                color_foreground = COLOR_YELLOW;

                auto hor_skeleton = dynamic_cast<HorizontalSkeleton *>(m_cell->topCreature());
                if (hor_skeleton->getPatrollingRight() == true) {
                    wstr = L"┞↠";
                } else {
                    wstr = L"↞┦";
                }
                break;
            }
            case TVerticalScorpion: {
                color_foreground = COLOR_YELLOW;

                auto vert_scorpion = dynamic_cast<VerticalScorpion *>(m_cell->topCreature());
                if (vert_scorpion->getPatrollingTop() == true) {
                    wstr = L"ᖿᖼ";
                } else {
                    wstr = L"ᖽᖾ";
                }

                break;
            }

            case TPlayer: {
                color_foreground = COLOR_WHITE;

                auto player = dynamic_cast<Player *>(m_cell->topCreature());
                int dir_horizontal = player->getHorizontalDirection();
                int dir_vertical = player->getVerticalDirection();

                if (dir_horizontal == 0 and dir_vertical == 1) {
                    wstr = L"⮟ ";
                }
                if (dir_horizontal == 0 and dir_vertical == -1) {
                    wstr = L"⮝ ";
                }
                if (dir_horizontal == 1 and dir_vertical == 0) {
                    wstr = L"⮞ ";
                }
                if (dir_horizontal == -1 and dir_vertical == 0) {
                    wstr = L"⮜ ";
                }
                break;
            }

            case TCleverAlien: {
                attron(A_BOLD);
                color_foreground = COLOR_YELLOW;
                wstr = L"⍾ ";
                break;
            }


        }
        if (m_cell->topCreature()->getCurrTimeViewAttacked() != 0) {
            color_foreground = COLOR_RED;
            m_cell->topCreature()->updateCurrTimeViewAttacked();
        }

        color_pair = _convertToColorPair(color_foreground, color_background);
        attron(COLOR_PAIR(color_pair));
        addwstr(wstr);
        attroff(COLOR_PAIR(color_pair));
        attroff(A_BOLD);
        return;


    }


    color_pair = _convertToColorPair(color_foreground, color_background);
    attron(COLOR_PAIR(color_pair));
    addwstr(L"  ");
    attroff(COLOR_PAIR(color_pair));

}

ColorText ViewCell::_convertToColorPair(int front, int back) {
    if ((front == COLOR_WHITE)and(back == COLOR_CYAN)){
        return Color_FWhite_BCyan;
    }
    if ((front == COLOR_WHITE)and(back == COLOR_GREEN)){
        return Color_FWhite_BGreen;
    }
    if ((front == COLOR_WHITE)and(back == COLOR_RED)){
        return Color_FWhite_BRed;
    }
    if ((front == COLOR_WHITE)and(back == COLOR_BLACK)){
        return Color_FWhite_BBlack;
    }
    if ((front == COLOR_BLUE)and(back == COLOR_BLACK)){
        return Color_FBlue_BBlack;
    }
    if ((front == COLOR_GREEN)and(back == COLOR_BLACK)){
        return Color_FGreen_BBlack;
    }
    if ((front == COLOR_CYAN)and(back == COLOR_BLACK)){
        return Color_FCyan_BBlack;
    }
    if ((front == COLOR_YELLOW)and(back == COLOR_BLACK)){
        return Color_FYellow_BBlack;
    }
    if ((front == COLOR_RED)and(back == COLOR_BLACK)){
        return Color_FRed_BBlack;
    }
    if ((front == COLOR_BLUE)and(back == COLOR_RED)){
        return Color_FBlue_BRed;
    }
    if ((front == COLOR_GREEN)and(back == COLOR_RED)){
        return Color_FGreen_BRed;
    }
    if ((front == COLOR_MAGENTA)and(back == COLOR_BLACK)){
        return Color_FMagneta_BBlack;
    }


    return Color_Default;
}

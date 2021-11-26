#include "ViewCell.h"
#include "iostream"
#include "ICreature.h"
#include "IItem.h"
#include "Console.h"
#include "HorizontalSkeleton.h"
#include "VerticalScorpion.h"

void ViewCell::setModel(ICell &cell) {
 m_cell = &cell;
}

void ViewCell::draw() {
    switch (m_cell->getTypeCell()) {
        case TNormalCell:
            g_console.setTextAttrib(B_BLACK);
            std::wcout << "  ";
            break;
        case TEndCell:
            g_console.setTextAttrib(B_RED);
            std::wcout << "  ";
            break;
        case TStartCell:
            std::wcout << "\x1b[42m  ";
            break;
        case TImpassableCell:
            g_console.setTextAttrib(B_CYAN);
            std::wcout << "  ";
            break;
    }



    if (m_cell->topItem()) { //проверка на nullptr
        g_console.toLeftCursor();

        switch (m_cell->topItem()->getTypeItem()) {
            case TSword: {
                g_console.setTextAttrib(F_BLUE);
                std::wcout << L"🗡 ";

                break;
            }

            case TCroissant: {
                g_console.setTextAttrib(F_GREEN);
                std::wcout << L"✙ ";

                break;
            }

            case TShield: {
                g_console.setTextAttrib(F_CYAN);
                std::wcout << L"⛨ ";

                break;
            }


        }

    }




    if (m_cell->topCreature()) { //проверка на nullptr
        g_console.toLeftCursor();

        switch (m_cell->topCreature()->getTypeCreature()) {
            case THorizontalSkeleton: {
                g_console.setTextAttrib(F_YELLOW);

                auto hor_skeleton = dynamic_cast<HorizontalSkeleton *>(m_cell->topCreature());
                if (hor_skeleton->getPatrollingRight() == true) {
                    std::wcout << L"┞↠";
                } else {
                    std::wcout << L"↞┦";
                }
                break;
            }
            case TVerticalScorpion: {
                g_console.setTextAttrib(F_YELLOW);

                auto vert_scorpion = dynamic_cast<VerticalScorpion *>(m_cell->topCreature());
                if (vert_scorpion->getPatrollingTop() == true) {
                    std::wcout << L"ᖿᖼ";
                } else {
                    std::wcout << L"ᖽᖾ";
                }

                break;
            }

            case TPlayer: {
                g_console.setTextAttrib(F_WHITE);
                std::wcout << L"⮟ "; //

                break;
            }

            case TCleverAlien: {
                std::wcout << L"👾";

                break;
            }


        }
    }






    g_console.resetTextColor();
}

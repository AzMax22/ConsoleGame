#ifndef CONSOLE_GAME_SETKEYS_H
#define CONSOLE_GAME_SETKEYS_H

#include "string"

class SetKeys{
public:
    static std::vector<int> keyUp ;
    static std::vector<int> keyDown ;
    static std::vector<int> keyLeft ;
    static std::vector<int> keyRight ;
};


std::vector<int> SetKeys::keyUp = {KEY_UP,L'w',L'W', L'ц', L'Ц'};
std::vector<int> SetKeys::keyDown = {KEY_DOWN,L's',L'S', L'ы', L'Ы'} ;
std::vector<int> SetKeys::keyLeft = {KEY_LEFT,L'a',L'A', L'ф', L'Ф'};
std::vector<int> SetKeys::keyRight = {KEY_RIGHT,L'd',L'D', L'в', L'В'};
#endif //CONSOLE_GAME_SETKEYS_H

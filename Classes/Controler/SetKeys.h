#ifndef CONSOLE_GAME_SETKEYS_H
#define CONSOLE_GAME_SETKEYS_H

#include "string"

class SetKeys{
public:
    static std::wstring keyUp ;
    static std::wstring keyDown ;
    static std::wstring keyLeft ;
    static std::wstring keyRight ;
};


std::wstring SetKeys::keyUp = L"wWцЦ" ;
std::wstring SetKeys::keyDown = L"SsЫы" ;
std::wstring SetKeys::keyLeft = L"aAфФ";
std::wstring SetKeys::keyRight = L"dDвВ";
#endif //CONSOLE_GAME_SETKEYS_H

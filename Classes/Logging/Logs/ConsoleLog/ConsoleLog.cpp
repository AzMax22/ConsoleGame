//
// Created by maxim on 17.11.2021.
//

#include "ConsoleLog.h"
#include "iostream"
#include <string>
#include <codecvt>
#include <locale>

std::ostream &ConsoleLog::steam() {
    return m_string;
}

void ConsoleLog::update() {
    std::wcout << std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(m_string.str());
    m_string.str("");
    m_string << std::endl << "-----------------------------------Console Log-----------------------------------" << std::endl;
}

ConsoleLog::ConsoleLog() {
    m_string << std::endl << "-----------------------------------Console Log-----------------------------------" << std::endl;
}

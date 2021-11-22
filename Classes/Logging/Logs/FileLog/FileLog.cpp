//
// Created by maxim on 16.11.2021.
//

#include "FileLog.h"

FileLog::FileLog(std::string name) {
    m_file.open(name);
    m_file  << "------------------------------------File Log-------------------------------------" << std::endl;
}

std::ostream &FileLog::steam() {
    return m_file;
}

FileLog::~FileLog() {
    m_file.close();
}

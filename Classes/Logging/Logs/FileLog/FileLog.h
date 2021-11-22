#ifndef CONSOLE_GAME_FILELOG_H
#define CONSOLE_GAME_FILELOG_H

#include "ILog.h"
#include <fstream>


class FileLog : public ILog{
    std::ofstream m_file;
public:
    FileLog(std::string name);
    std::ostream & steam() override;
    ~FileLog();
};


#endif //CONSOLE_GAME_FILELOG_H

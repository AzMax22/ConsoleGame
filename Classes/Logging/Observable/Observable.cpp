//
// Created by maxim on 11.11.2021.
//

#include "Observable.h"


void Observable::bindWithLogger(Logger* logger)
{
    m_logger = logger;
}

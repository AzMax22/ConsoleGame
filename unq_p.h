#ifndef CONSOLE_GAME_UNQ_P_H
#define CONSOLE_GAME_UNQ_P_H

#include <memory>

template<typename T> using unq_p = std::unique_ptr<T> ;
template<typename T> using arr_unq =  unq_p< unq_p<T>[] > ;
template<typename T> using arr2d_unq =  unq_p< arr_unq<T>[] > ;

#endif //CONSOLE_GAME_UNQ_P_H

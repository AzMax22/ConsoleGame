

#include "Game.h"
#include <ncursesw/ncurses.h>

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
Game<GenLevel, RSetLocatedObj, RWinAndLose>::Game(GenLevel& genlevel, RSetLocatedObj& r_set_located, RWinAndLose& r_win_lose)
: m_r_win_lose(r_win_lose){

    //инициализация строителя
    BuilderField builder;

    //создание поля
    m_field = genlevel.generationField();

    //инициализация логерра
    auto cons_log = std::make_unique<ConsoleLog>();
    auto f_log = std::make_unique<FileLog>("flog.txt");
    m_logger = std::make_unique<Logger>(std::move(f_log));


    //создание игрока
    m_player= r_set_located.getPlayer(m_field.get(), m_logger.get());

    //создание существ
    m_set_update_obj = r_set_located.getSetEnemy(m_field.get(), m_logger.get(), m_player.get());

    //создание предметов
    r_set_located.setItem(m_field.get(), m_logger.get());

}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
void Game<GenLevel, RSetLocatedObj, RWinAndLose>::update() {
    m_player->update();


    for (int i = 0 ; i < m_set_update_obj.size(); i++ ){
        if (m_set_update_obj[i]->getAlive()){
            m_set_update_obj[i]->update();
        } else {
            m_set_update_obj.erase(m_set_update_obj.begin() + i);
        }

    }



    if (m_r_win_lose.win(this)){

        state_game = WIN;

        EventEndGame event(this);
        m_logger->processNotification<Game>(event);
        return;
    }

    if (m_r_win_lose.lose(this)){

        state_game = LOSE;

        EventEndGame event(this);
        m_logger->processNotification<Game>(event);
        return;
    }
}


template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
Game<GenLevel, RSetLocatedObj, RWinAndLose>::~Game() {

}


template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
Field* Game<GenLevel, RSetLocatedObj, RWinAndLose>::getField() {
    return m_field.get();
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
StateGame Game<GenLevel, RSetLocatedObj, RWinAndLose>::gameState() {
    return state_game;
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
Logger* Game<GenLevel, RSetLocatedObj, RWinAndLose>::getLogger() {
    return m_logger.get();
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
std::string Game<GenLevel, RSetLocatedObj, RWinAndLose>::name() {
    return "Игра ";
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
void Game<GenLevel, RSetLocatedObj, RWinAndLose>::movePlayer(int inc_x, int inc_y) {
    m_player->move(inc_x,inc_y);
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
Player* Game<GenLevel, RSetLocatedObj, RWinAndLose>::getPlayer() {
    return m_player.get();
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
void Game<GenLevel, RSetLocatedObj, RWinAndLose>::gameExit() {
    state_game = EXIT;
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
void Game<GenLevel, RSetLocatedObj, RWinAndLose>::attackPlayer() {
    m_player->attack();
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
bool Game<GenLevel, RSetLocatedObj, RWinAndLose>::save(std::string name) {
    std::ofstream file;
    std::string dir("Save") ;

    error_code ec;
    if (!filesystem::exists(dir) or !filesystem::is_directory( filesystem::status(dir))){
        filesystem::create_directories(dir,ec);
    }

    if (ec){
        return false;
    }

    string path(dir + "/" + name + ".save");
    file.open(path);

    file << m_field->save();
    file << m_player->save() << endl;

    file << m_set_update_obj.size() << endl;
    for (int i = 0; i < m_set_update_obj.size();i++) {
        file << m_set_update_obj[i]->save() << "\n";
    }


    file.close();

    return true;
}

template<class GenLevel, class RSetLocatedObj, class RWinAndLose>
bool Game<GenLevel, RSetLocatedObj, RWinAndLose>::loadSave(std::string name) {
    save(".tmp");
    m_field->deleteItems();

    string line;
    istringstream data_save;
    std::ifstream file;
    string path("Save/" + name + ".save");

    file.open(path);
    int level,n_items,n_creat;

    file >> level;
    file >> n_items;

    for (int i = 0; i < n_items; i++){
        getline(file,line);
        data_save.str(line);
    }



    file.close();

    return true;
}


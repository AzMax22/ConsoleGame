

template<class GenLevel, class RSetLocatedObj>
Game<GenLevel, RSetLocatedObj>::Game(GenLevel& genlevel, RSetLocatedObj& r_set_located) {
    //инициализация объектов
    BuilderField builder;


    /*auto curos = std::make_unique<Croissant>();
    auto sword = std::make_unique<Sword>();
    auto shield = std::make_unique<Shield>();
    auto skelet = std::make_unique<HorizontalSkeleton>();
    auto skelet2 = std::make_unique<HorizontalSkeleton>();
    auto scorpion = std::make_unique<VerticalScorpion>();*/

    //m_player = std::make_unique<Player>(); //создание игрока


    //строительство поля
    /*builder.createEmptyField(30,20); //диапазон x = [1,20], y = [1,20]



    builder.buildEndCell(30, 20);
    m_field = builder.getField();*/


    //инициализация логерра
    auto cons_log = std::make_unique<ConsoleLog>();
    auto f_log = std::make_unique<FileLog>("flog.txt");
    m_logger = std::make_unique<Logger>(std::move(f_log));
    m_logger->addLog(std::move(cons_log));

    m_field = genlevel.generationField();
    m_player= r_set_located.getPlayer(m_field.get(), m_logger.get());
    m_set_update_obj = r_set_located.getSetEnemy(m_field.get(), m_logger.get(), m_player.get());
    r_set_located.setItem(m_field.get(), m_logger.get());

    //m_logger->addObservable(m_set_update_obj[0].get());
   // m_logger->addObservable(m_alien.get());
    //m_logger->addObservable(m_player.get());
    /*logger.addObservable(skelet.get());
    logger.addObservable(skelet2.get());
    logger.addObservable(scorpion.get());

    logger.addObservable(sword.get());
    logger.addObservable(curos.get());
    logger.addObservable(shield.get());*/

    //m_alien->follow(m_player.get());
    //m_player->setLocation(1, 2, m_field.get());
    //m_alien->setLocation(20, 1, m_field.get());
    /*skelet->setLocation(15, 1, field1.get());
    scorpion->setLocation(5, 5, field1.get());
    sword->setLocation(1, 1, std::move(sword), field1.get());
    curos->setLocation(15, 10, std::move(curos), field1.get());
    shield->setLocation(1, 10, std::move(shield), field1.get());
    skelet2->setLocation(20, 20, field1.get());*/

}

template<class GenLevel, class RSetLocatedObj>
void Game<GenLevel, RSetLocatedObj>::update() {
    /*if (m_player->getAlive()){
        if(m_player->win()){
            state_game = WIN;

            EventEndGame event(this);
            m_logger->processNotification<Game>(event);
            return;
        }
        m_player->update();
    } else {
        state_game = LOSE;

        EventEndGame event(this);
        m_logger->processNotification<Game>(event);
        return;
    }

    if (m_alien->getAlive()){
        m_alien->update();
    }*/

    m_player->update();

    for (int i = 0 ; i < m_set_update_obj.size(); i++ ){
        m_set_update_obj[i]->update();
    }
}


template<class GenLevel, class RSetLocatedObj>
Game<GenLevel, RSetLocatedObj>::~Game() {

}

template<class GenLevel, class RSetLocatedObj>
Field *Game<GenLevel, RSetLocatedObj>::getField() {
    return m_field.get();
}

template<class GenLevel, class RSetLocatedObj>
StateGame Game<GenLevel, RSetLocatedObj>::gameState() {
    return state_game;
}

template<class GenLevel, class RSetLocatedObj>
Logger *Game<GenLevel, RSetLocatedObj>::getLogger() {
    return m_logger.get();
}

template<class GenLevel, class RSetLocatedObj>
std::string Game<GenLevel, RSetLocatedObj>::name() {
    return "Игра ";
}

template<class GenLevel, class RSetLocatedObj>
void Game<GenLevel, RSetLocatedObj>::movePlayer(int inc_x, int inc_y) {
    m_player->move(inc_x,inc_y);
}


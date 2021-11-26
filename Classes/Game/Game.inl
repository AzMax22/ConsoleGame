

template<class GenLevel>
Game<GenLevel>::Game(GenLevel& genlevel) {
    //инициализация объектов
    BuilderField builder;
    m_alien = std::make_unique<CleverAlien>();

    /*auto curos = std::make_unique<Croissant>();
    auto sword = std::make_unique<Sword>();
    auto shield = std::make_unique<Shield>();
    auto skelet = std::make_unique<HorizontalSkeleton>();
    auto skelet2 = std::make_unique<HorizontalSkeleton>();
    auto scorpion = std::make_unique<VerticalScorpion>();*/

    m_player = std::make_unique<Player>(); //создание игрока


    //строительство поля
    /*builder.createEmptyField(30,20); //диапазон x = [1,20], y = [1,20]



    builder.buildEndCell(30, 20);
    m_field = builder.getField();*/
    m_field = genlevel.generationField();

    //инициализация логерра
    auto cons_log = std::make_unique<ConsoleLog>();
    auto f_log = std::make_unique<FileLog>("flog.txt");
    m_logger = std::make_unique<Logger>(std::move(f_log));
    m_logger->addLog(std::move(cons_log));

    m_logger->addObservable(m_alien.get());
    m_logger->addObservable(m_player.get());
    /*logger.addObservable(skelet.get());
    logger.addObservable(skelet2.get());
    logger.addObservable(scorpion.get());

    logger.addObservable(sword.get());
    logger.addObservable(curos.get());
    logger.addObservable(shield.get());*/

    m_alien->follow(m_player.get());
    m_player->setLocation(1, 2, m_field.get());
    m_alien->setLocation(20, 1, m_field.get());
    /*skelet->setLocation(15, 1, field1.get());
    scorpion->setLocation(5, 5, field1.get());
    sword->setLocation(1, 1, std::move(sword), field1.get());
    curos->setLocation(15, 10, std::move(curos), field1.get());
    shield->setLocation(1, 10, std::move(shield), field1.get());
    skelet2->setLocation(20, 20, field1.get());*/

}

template<class GenLevel>
void Game<GenLevel>::update() {
    if (m_player->getAlive()){
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
    }
}

template<class GenLevel>
Game<GenLevel>::~Game() {

}

template<class GenLevel>
Field *Game<GenLevel>::getField() {
    return m_field.get();
}

template<class GenLevel>
StateGame Game<GenLevel>::gameState() {
    return state_game;
}

template<class GenLevel>
Logger *Game<GenLevel>::getLogger() {
    return m_logger.get();
}

template<class GenLevel>
std::string Game<GenLevel>::name() {
    return "Игра ";
}

template<class GenLevel>
void Game<GenLevel>::movePlayer(int inc_x, int inc_y) {
    m_player->move(inc_x,inc_y);
}


#include "Game.h"


Game::Game() {
    //инициализация объектов
    BuilderField builder;
    m_alien = std::make_unique<CleverAlien>();

    /*auto curos = std::make_unique<Croissant>();
    auto sword = std::make_unique<Sword>();
    auto shield = std::make_unique<Shield>();
    auto skelet = std::make_unique<HorizontalSkeleton>();
    auto skelet2 = std::make_unique<HorizontalSkeleton>();
    auto scorpion = std::make_unique<VerticalScorpion>();*/

    //строительство поля
    builder.createEmptyField(20,20); //диапазон x = [1,20], y = [1,30]
    //builder.buildRandomImpassableCells(20);
    m_player = builder.buildStartCell(8, 1);
    builder.buildEndCell();
    builder.buildEndCell();
    m_field = builder.getField();

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
    m_alien->setLocation(20, 20, m_field.get());
    /*skelet->setLocation(15, 1, field1.get());
    scorpion->setLocation(5, 5, field1.get());
    sword->setLocation(1, 1, std::move(sword), field1.get());
    curos->setLocation(15, 10, std::move(curos), field1.get());
    shield->setLocation(1, 10, std::move(shield), field1.get());
    skelet2->setLocation(20, 20, field1.get());*/

}

void Game::update() {
    if (m_player->getAlive()){
        if(m_player->win()){
            state_game = WIN;

            EventEndGame event(this);
            m_logger->processNotification(event);
            return;
        }
        m_player->update();
    } else {
        state_game = LOSE;

        EventEndGame event(this);
        m_logger->processNotification(event);
        return;
    }

    if (m_alien->getAlive()){
        m_alien->update();
    }
}

Game::~Game() {

}

Field *Game::getField() {
    return m_field.get();
}

StateGame Game::gameState() {
    return state_game;
}

Logger *Game::getLogger() {
    return m_logger.get();
}

std::string Game::name() {
    return "Игра ";
}

void Game::movePlayer(int inc_x, int inc_y) {
    m_player->move(inc_x,inc_y);
}


#ifndef CONSOLE_GAME_RULESETLOCATEDGAMEOBJ_H
#define CONSOLE_GAME_RULESETLOCATEDGAMEOBJ_H

#include "IAutonomy.h"
#include <vector>
#include "unq_p.h"
#include "Player.h"
#include "Logger.h"
#include "VerticalScorpion.h"
#include "HorizontalSkeleton.h"
#include "CleverAlien.h"
#include "Sword.h"
#include "Croissant.h"
#include "Shield.h"



template<int level, int option>
class RuleSetLocatedGameObj{
public:
    std::vector<unq_p<IAutonomy>> getSetEnemy(Field* filed, Logger* logger, Player* player){
        std::vector<unq_p<IAutonomy>> vec;


        return vec;
    }

    void setItem(Field* filed, Logger* logger){
    }

    unq_p<Player> getPlayer(Field* filed, Logger* logger){

        auto player = std::make_unique<Player>();
        logger->addObservable(player.get());
        player->setLocation(1,1, filed);


        return std::move(player);
    }

};


template<>
class RuleSetLocatedGameObj<1,1>{

    Field* m_filed = nullptr;
    Logger* m_logger = nullptr;
    Player* m_player = nullptr;

    template<class Enemy>
    unq_p<Enemy> _createEnemy(int x, int y){
        auto enemy = std::make_unique<Enemy>();
        m_logger->addObservable(enemy.get());
        enemy->setLocation(x, y, m_filed);
        return std::move(enemy);
    }

    template<class Item>
    void _createItem(int x, int y){
        auto item = std::make_unique<Item>();
        m_logger->addObservable(item.get());
        item->setLocation(x, y, std::move(item), m_filed);
    }


    unq_p<CleverAlien> _createEnemyCleverAlien(int x, int y) {
        auto alien = _createEnemy<CleverAlien>(x, y);
        alien->follow(m_player);
        return std::move(alien);
    }

public:
    std::vector<unq_p<IAutonomy>> getSetEnemy(Field* filed, Logger* logger, Player* player){
        std::vector<unq_p<IAutonomy>> vec;
        m_filed = filed;
        m_logger = logger;
        m_player = player;

        vec.push_back(_createEnemy<VerticalScorpion>(20,3));
        vec.push_back(_createEnemy<VerticalScorpion>(9,14));
        vec.push_back(_createEnemy<HorizontalSkeleton>(15,15));
        vec.push_back(_createEnemyCleverAlien(26,18));

        return vec;
    }

    void setItem(Field* filed, Logger* logger){
        m_filed = filed;
        m_logger = logger;

        _createItem<Sword>(5, 1);
        _createItem<Croissant>(28, 3);
        _createItem<Shield>(5, 18);

    }

    unq_p<Player> getPlayer(Field* filed, Logger* logger){

        auto player = std::make_unique<Player>();
        logger->addObservable(player.get());
        player->setLocation(1,1, filed);


        return std::move(player);
    }

};


#endif //CONSOLE_GAME_RULESETLOCATEDGAMEOBJ_H

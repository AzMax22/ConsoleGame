#include "Logger.h"
#include "ICreature.h"
#include "LocatedObject.h"
#include "GameObject.h"

Logger::Logger(unq_p<ILog> some_steam) {
    logs.push_back(std::move(some_steam));
}



void Logger::update() {
    /*if (something_happened == false){ return;}

    for(auto&& some_log : logs){
        some_log->steam() << "---------------------------------------------------------------------------------" << std::endl;
        some_log->update();
    }
    something_happened = false;*/

}

void Logger::addLog(unq_p<ILog> some_steam) {
    logs.push_back(std::move(some_steam));
}

void Logger::addObservable(Observable* some_obsle) {
    some_obsle->bindWithLogger(this);
}


void Logger::processNotification(EventMove& event) {
    auto &obj = dynamic_cast<LocatedObject&>(event.getObjEvent());
    std::string move_where;

    if (event.getIncX() == 0) {
        if (event.getIncY()  > 0) {
            move_where = "вниз ";
        }

        if (event.getIncY() < 0) {
            move_where = "вверх ";
        }
    }

    if (event.getIncY() == 0) {
        if (event.getIncX() > 0) {
            move_where = "вправо ";
        }

        if (event.getIncX() < 0) {
            move_where = "влево ";
        }
    }

    for(auto&& some_log : logs){
        some_log->steam() << event.getObjEvent() << "переместился " << move_where << ", текущее местоположение " \
        <<"x = " << obj.getX() << ", y = " << obj.getY() << std::endl;
    }
}


void Logger::processNotification(EventReversal &event) {
    auto &obj = dynamic_cast<LocatedObject&>(event.getObjEvent());

    for(auto&& some_log : logs){
        some_log->steam() << event.getObjEvent() << "развернулся " << ", текущее местоположение " \
        <<"x = " << obj.getX() << ", y = " << obj.getY() << std::endl;
    }
}

void Logger::processNotification(EventChangeHealth &event) {
    auto &obj = dynamic_cast<ICreature&>(event.getObjEvent());

    if (event.getIncHealth() > 0) {
        for(auto&& some_log : logs) {
            some_log->steam() << event.getObjEvent() << "восстановил здоровье на " << event.getIncHealth() << " ед." \
            << ", текущее здоровье " << obj.getHealth() << "/" << obj.getMaxHealth() << std::endl;
        }
    } else {
        int real_damage = -event.getIncHealth() - obj.getArmor();
        if (real_damage < 0) { real_damage = 0; }

        for (auto &&some_log: logs) {
            some_log->steam() << event.getObjEvent() << "получил урон в " << -event.getIncHealth() << " ед." \
            << ", c учетом защиты в " << obj.getArmor() << " ед." << ", реальный урон " << real_damage \
            << " ед." << ", текущее здоровье " << obj.getHealth() << "/" << obj.getMaxHealth() << std::endl;
        }
    }
}

void Logger::processNotification(EventChangeArmor &event) {
    auto &obj = dynamic_cast<ICreature&>(event.getObjEvent());

    if (event.getIncArmor() > 0) {
        for(auto&& some_log : logs) {
            some_log->steam() << event.getObjEvent() << "увеличил показатель брони на " << event.getIncArmor() << " ед." \
            << ", текущее кол-во брони " << obj.getArmor()  << std::endl;
        }
    } else
        for(auto&& some_log : logs) {
            some_log->steam() << event.getObjEvent() << "уменьшил показатель брони на " << -event.getIncArmor() << " ед." \
            << ", текущее кол-во брони " << obj.getArmor()  << std::endl;
        }
}

void Logger::processNotification(EventChangeDamage &event) {
    auto &obj = dynamic_cast<ICreature&>(event.getObjEvent());

    if (event.getIncDamage() > 0) {
        for(auto&& some_log : logs) {
            some_log->steam() << event.getObjEvent() << "увеличил показатель урона на " << event.getIncDamage() << " ед." \
            << ", текущее значение урона " << obj.getDamage()  << std::endl;
        }
    } else
        for(auto&& some_log : logs) {
            some_log->steam() << event.getObjEvent() << "уменьшил показатель урона на " << -event.getIncDamage() << " ед." \
            << ", текущее значение урона " << obj.getDamage()  << std::endl;
        }
}

void Logger::processNotification(EventToAttack &event) {
    auto &obj = dynamic_cast<ICreature&>(event.getObjEvent());

    for(auto&& some_log : logs) {
        some_log->steam() << event.getObjEvent() << "атковал " << event.getAnotherObj() \
        << ", урон атаки " << obj.getDamage() << " ед." << std::endl;
    }
}

void Logger::processNotification(EventSetLocation &event) {
    auto &obj = dynamic_cast<LocatedObject&>(event.getObjEvent());

    for(auto&& some_log : logs) {
        some_log->steam() << event.getObjEvent() << "поставлен на координаты " <<"x = " \
        << obj.getX() << ", y = " << obj.getY() << std::endl;
    }
}

void Logger::processNotification(EventDeath &event) {
    for(auto&& some_log : logs) {
        some_log->steam() << event.getObjEvent() << "умер " << std::endl;
    }
}

void Logger::processNotification(EventAffect &event) {
    for(auto&& some_log : logs) {
        some_log->steam() <<  event.getAnotherObj() << "подобрал " <<event.getObjEvent()  << std::endl;
    }
}

/*void Logger::somethingHappened() {
    something_happened = true;
}*/

void Logger::processNotification(EventChangeMaxHealth &event) {
    auto &obj = dynamic_cast<ICreature&>(event.getObjEvent());

    if (event.getIncHealth() > 0) {
        for(auto&& some_log : logs) {
            some_log->steam() << event.getObjEvent() << "увеличил макс. здоровье на " << event.getIncHealth() << " ед." \
            << ", текущее макс. здоровье " <<  obj.getMaxHealth() << std::endl;
        }
    } else {
        for (auto &&some_log: logs) {
            some_log->steam() << event.getObjEvent() << "уменьшил макс. здоровье на " << -event.getIncHealth() << " ед." \
            << ", текущее макс. здоровье " <<  obj.getMaxHealth() << std::endl;
        }
    }
}





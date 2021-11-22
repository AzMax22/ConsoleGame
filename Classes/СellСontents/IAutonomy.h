#ifndef CONSOLE_GAME_IAUTONOMY_H
#define CONSOLE_GAME_IAUTONOMY_H

//интерфейс классов котрые имею "автономное поведение" , независимое от игрока(человека)
class IAutonomy {
protected:
    bool m_alive = true;
public:
    virtual  void update() = 0; //обновление ("реализация поведения")
    virtual void death() = 0; //удаление обьекта
    bool getAlive();
    virtual ~IAutonomy() = default;
};




#endif //CONSOLE_GAME_IAUTONOMY_H



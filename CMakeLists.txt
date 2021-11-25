cmake_minimum_required(VERSION 3.20)
project(Console_Game)

set(CMAKE_CXX_STANDARD 23)


add_executable(Console_Game main.cpp
        Classes/Field/Field.cpp
        Classes/Field/Field.h
        Classes/BuilderField/BuilderField.cpp
        Classes/BuilderField/BuilderField.h
        Classes/Cells/ICell.h
        Classes/Cells/NormalCell/NormalCell.cpp Classes/Cells/NormalCell/NormalCell.h
        Classes/СellСontents/Items/IItem.h
        Classes/СellСontents/Сreatures/ICreature.h
        Classes/Cells/StartCell/StartCell.cpp Classes/Cells/StartCell/StartCell.h
        Classes/Cells/EndCell/EndCell.cpp Classes/Cells/EndCell/EndCell.h
        unq_p.h My_Exception.h
        Classes/View/ViewField/ViewField.cpp Classes/View/ViewField/ViewField.h
        Classes/СellСontents/Сreatures/Player/Player.cpp Classes/СellСontents/Сreatures/Player/Player.h
        Classes/View/ViewCell/ViewCell.cpp Classes/View/ViewCell/ViewCell.h
        Classes/Console/Console.h Classes/СellСontents/Сreatures/ICreature.cpp
        Classes/СellСontents/IAutonomy.h Classes/СellСontents/Сreatures/Enemies/HorizontalSkeleton/HorizontalSkeleton.cpp
        Classes/СellСontents/Сreatures/Enemies/HorizontalSkeleton/HorizontalSkeleton.h
        Classes/Console/Console.cpp Classes/СellСontents/IAutonomy.cpp
        Classes/СellСontents/Сreatures/Enemies/VerticalScorpion/VerticalScorpion.cpp
        Classes/СellСontents/Сreatures/Enemies/VerticalScorpion/VerticalScorpion.h
        Classes/СellСontents/Items/Sword/Sword.cpp Classes/СellСontents/Items/Sword/Sword.h
        Classes/СellСontents/Items/IItem.cpp Classes/СellСontents/Items/Croissant/Croissant.cpp
        Classes/СellСontents/Items/Croissant/Croissant.h
        Classes/СellСontents/Items/Shield/Shield.cpp Classes/СellСontents/Items/Shield/Shield.h
        Classes/СellСontents/Сreatures/Enemies/CleverAlien/CleverAlien.cpp
        Classes/СellСontents/Сreatures/Enemies/CleverAlien/CleverAlien.h
        Classes/Logging/Observable/Observable.cpp Classes/Logging/Observable/Observable.h
        Classes/Logging/Logger/Logger.cpp Classes/Logging/Logger/Logger.h
        Classes/GameObject/GameObject.cpp Classes/GameObject/GameObject.h
        Classes/Logging/Logs/FileLog/FileLog.cpp Classes/Logging/Logs/FileLog/FileLog.h
        Classes/Event/Event.h Classes/Event/Event.cpp Classes/Logging/Logs/ConsoleLog/ConsoleLog.cpp
        Classes/Logging/Logs/ConsoleLog/ConsoleLog.h Classes/Logging/Logs/ILog.cpp
        Classes/Game/Game.cpp Classes/Game/Game.h
        Classes/View/ViewGame/ViewGame.cpp Classes/View/ViewGame/ViewGame.h
        Classes/СellСontents/LocatedObject.h Classes/Controler/Controler.cpp
        Classes/Controler/Controler.h Classes/Controler/SetKeys.h)

target_include_directories(
        Console_Game                           # Цель, при сборке которой учитываются указанные пути к заголовочным файлам
        PUBLIC                                # область видимости (PRIVATE, INTERFACE или PUBLIC)
        Classes/Field/
        Classes/BuilderField/
        Classes/Controler/
        Classes/Logging/LogAdapterEN/
        Classes/Logging/Logs/FileLog/
        Classes/Logging/Logs
        Classes/Logging/Logs/ConsoleLog/
        Classes/Event
        Classes/СellСontents/
        Classes/View/ViewGame
        Classes/Game/
        Classes/Cells/NormalCell
        Classes/Cells/
        Classes/СellСontents/
        Classes/СellСontents/Items
        Classes/СellСontents/Сreatures/
        Classes/Cells/StartCell/
        Classes/Cells/EndCell/
        Classes/СellСontents/Сreatures/Enemies/HorizontalSkeleton
        Classes/СellСontents/Сreatures/Enemies/CleverAlien
        Classes/Logging/Observable/
        ./
        Classes/View/ViewField/
        Classes/СellСontents/Сreatures/Player
        Classes/View/ViewCell/
        Classes/Console
        Classes/My_List/
        Classes/СellСontents/Сreatures/Enemies/VerticalScorpion/
        Classes/СellСontents/Items/Croissant/
        Classes/СellСontents/Items/Shield/
        Classes/Logging/
        Classes/Logging/Logger/
        Classes/Logging/IGeneratorLogMes/
        Classes/GameObject/
        Classes/Events/IEvent/
        Classes/Logging/IGeneratorLogMes/GeneratorLogMesRU/
)


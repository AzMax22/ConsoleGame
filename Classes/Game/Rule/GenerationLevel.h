#ifndef CONSOLE_GAME_GENERATIONLEVEL_H
#define CONSOLE_GAME_GENERATIONLEVEL_H

#include "BuilderField.h"

template<int level>
class GenerationLevel {
    BuilderField builder;

public:
    unq_p<Field> generationField() {
        builder.createEmptyField(20,20); //диапазон x = [1,20], y = [1,20]
        builder.buildEndCell(20, 20);
        return builder.getField();
    }
};


template<>
class GenerationLevel<1> {
    BuilderField builder;

public:
    unq_p<Field> generationField() {
        builder.createEmptyField(30,20); //диапазон x = [1,20], y = [1,20]

        builder.buildWall(6,1,6,5);
        builder.buildWall(1,5,2,5);
        builder.buildWall(4,5,6,5);
        builder.buildWall(1,11,16,11);
        builder.buildWall(14,6,25,6);
        builder.buildWall(28,6,30,6);
        builder.buildWall(11,15,11,20);
        builder.buildWall(5,15,11,15);
        builder.buildWall(21,14,30,14);
        builder.buildWall(21,14,21,17);

        builder.buildEndCell(20, 20);
        return builder.getField();
    }
};

#endif //CONSOLE_GAME_GENERATIONLEVEL_H

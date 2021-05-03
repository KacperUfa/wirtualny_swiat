//
// Created by kacpe on 03.05.2021.
//

#ifndef WIRTUALNY_SWIAT_WORLD_H
#define WIRTUALNY_SWIAT_WORLD_H
#include "Position.h"
class Organism;


class World {
private:
    Organism *organisms;
    Position mapSize;
public:
    World(Position mapSize, Organism *organisms);
    void makeTurn();
    void drawWorld();
    ~World();
};

#include "Organism.h"
#endif //WIRTUALNY_SWIAT_WORLD_H

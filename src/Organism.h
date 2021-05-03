//
// Created by kacpe on 03.05.2021.
//

#ifndef WIRTUALNY_SWIAT_ORGANISM_H
#define WIRTUALNY_SWIAT_ORGANISM_H

#include "World.h"
#include "Position.h"


class Organism {
protected:
    const int power;
    const int initiative;
    Position position;
    World *world;
public:
    Organism(int power, int initiative, int x, int y, World *world);
    virtual void action();
    virtual void collision();
    virtual void draw();
    virtual ~Organism();

};


#endif //WIRTUALNY_SWIAT_ORGANISM_H

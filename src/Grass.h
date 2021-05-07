#ifndef WIRTUALNY_SWIAT_GRASS_H
#define WIRTUALNY_SWIAT_GRASS_H

#include "Plant.h"
#include <iostream>

/*
Grass is the most basic plant in this whole simulator it can only multiply itself
 */

class Grass : public Plant {
public:
    Grass(int x, int y, World *world);

    void Draw() override;

    void SayName() override;

    void newPlant(Position *position) override;

    bool checkSpecies(Organism *organismTmp) override;

    std::string GetName();

    ~Grass();
};


#endif //WIRTUALNY_SWIAT_GRASS_H

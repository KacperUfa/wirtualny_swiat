#ifndef WIRTUALNY_SWIAT_NIGHTSHADE_H
#define WIRTUALNY_SWIAT_NIGHTSHADE_H

#include "Plant.h"
#include <iostream>

class Nightshade : public Plant {
public:
    Nightshade(int x, int y, World *world);

    void Draw() override;

    void SayName() override;

    void newPlant(Position *position) override;

    bool checkSpecies(Organism *organismTmp) override;

    void Collision(Organism *org, int x, int y, Position position) override;

    std::string GetName();

    ~Nightshade();
};


#endif //WIRTUALNY_SWIAT_NIGHTSHADE_H

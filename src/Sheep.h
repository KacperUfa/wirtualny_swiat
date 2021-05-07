#ifndef WIRTUALNY_SWIAT_SHEEP_H
#define WIRTUALNY_SWIAT_SHEEP_H

#include "Animal.h"

/*
Sheep is average animal without any additional actions
 */

class Sheep : public Animal {
public:
    Sheep(int x, int y, World *world);

    void Draw();

    void SayName() override;

    void newAnimal(Position *positionXY) override;

    bool checkSpecies(Organism *organismTmp) override;

    ~Sheep();
};


#endif //WIRTUALNY_SWIAT_SHEEP_H

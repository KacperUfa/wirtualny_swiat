#ifndef WIRTUALNY_SWIAT_ANTELOPE_H
#define WIRTUALNY_SWIAT_ANTELOPE_H

#include "Animal.h"

/*
Antelope moves 2 spaces instead of 1 and it has 50% chance to escape before fight on a free adjacent field
 */

class Antelope : public Animal {
public:
    Antelope(int x, int y, World *world);

    void Draw();

    void SayName() override;

    void newAnimal(Position *positionXY) override;

    bool checkSpecies(Organism *organismTmp) override;

    void Action() override;

    void Collision(Organism *org, int x, int y, Position position) override;

    ~Antelope();
};


#endif //WIRTUALNY_SWIAT_ANTELOPE_H

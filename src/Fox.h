#ifndef WIRTUALNY_SWIAT_FOX_H
#define WIRTUALNY_SWIAT_FOX_H

#include "Animal.h"
#include <iostream>

/*
Fox hase the biggest initiative, so it always moves first, but if it would move into stronger
animal it stops itself from doing that
 */

class Fox : public Animal {
public:
    Fox(int x, int y, World *world);

    void Draw();

    void SayName() override;

    void newAnimal(Position *positionXY) override;

    bool checkSpecies(Organism *organismTmp) override;

    std::string GetName();

    void Action() override;

    ~Fox();
};


#endif //WIRTUALNY_SWIAT_FOX_H

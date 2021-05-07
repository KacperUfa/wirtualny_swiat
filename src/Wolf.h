#ifndef WIRTUALNY_SWIAT_WOLF_H
#define WIRTUALNY_SWIAT_WOLF_H

#include "Animal.h"

/*
Wolf is the strongest animals but it doesn't have any special actions
 */

class Wolf : public Animal {
public:
    Wolf(int x, int y, World *world);

    void Draw();

    void SayName() override;

    void newAnimal(Position *positionXY) override;

    bool checkSpecies(Organism *organismTmp) override;

    ~Wolf();
};


#endif //WIRTUALNY_SWIAT_WOLF_H

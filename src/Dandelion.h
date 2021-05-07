#ifndef WIRTUALNY_SWIAT_DANDELION_H
#define WIRTUALNY_SWIAT_DANDELION_H
#include "Plant.h"

/*
Dandelion is a basic plant, but in it's action it tries 3 times to reproduce itself
 */

class Dandelion : public Plant {
public:
    Dandelion(int x, int y, World *world);
    void Draw() override;
    void Action() override;
    void SayName() override;
    void newPlant(Position *position) override;
    bool checkSpecies(Organism* organismTmp) override;
    ~Dandelion();
};


#endif //WIRTUALNY_SWIAT_DANDELION_H

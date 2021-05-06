#ifndef WIRTUALNY_SWIAT_DANDELION_H
#define WIRTUALNY_SWIAT_DANDELION_H
#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(int x, int y, World *world);
    void Draw() override;
    void Action() override;
    void newPlant(Position *position) override;
    bool checkSpecies(Organism* organismTmp) override;
    ~Dandelion();
};


#endif //WIRTUALNY_SWIAT_DANDELION_H

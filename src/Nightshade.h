#ifndef WIRTUALNY_SWIAT_NIGHTSHADE_H
#define WIRTUALNY_SWIAT_NIGHTSHADE_H
#include "Plant.h"

class Nightshade: public Plant {
public:
    Nightshade(int x, int y, World *world);
    void Draw() override;
    void newPlant(Position *position) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Nightshade();
};


#endif //WIRTUALNY_SWIAT_NIGHTSHADE_H

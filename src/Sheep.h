#ifndef WIRTUALNY_SWIAT_SHEEP_H
#define WIRTUALNY_SWIAT_SHEEP_H
#include "Animal.h"

class Sheep: public Animal {
public:
    Sheep(int x, int y, World *world);
    void Draw();
    bool checkSpecies(Organism* organismTmp) override;
    ~Sheep();
};


#endif //WIRTUALNY_SWIAT_SHEEP_H

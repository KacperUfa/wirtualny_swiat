#ifndef WIRTUALNY_SWIAT_SHEEP_H
#define WIRTUALNY_SWIAT_SHEEP_H
#include "Animal.h"

class Sheep: public Animal {
public:
    Sheep(int x, int y, World *world);
    void Draw();
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    //void Collision(Organism* org, int x, int y, Position position);
    ~Sheep();
};


#endif //WIRTUALNY_SWIAT_SHEEP_H

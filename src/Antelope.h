#ifndef WIRTUALNY_SWIAT_ANTELOPE_H
#define WIRTUALNY_SWIAT_ANTELOPE_H
#include "Animal.h"

class Antelope: public Animal {
public:
    Antelope(int x, int y, World *world);
    void Draw();
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Action() override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Antelope();
};


#endif //WIRTUALNY_SWIAT_ANTELOPE_H

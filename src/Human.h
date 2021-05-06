#ifndef WIRTUALNY_SWIAT_HUMAN_H
#define WIRTUALNY_SWIAT_HUMAN_H
#include "Animal.h"

class Human: public Animal {
public:
    Human(int x, int y, World *world);
    void Draw();
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Action() override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Human();
};


#endif //WIRTUALNY_SWIAT_HUMAN_H

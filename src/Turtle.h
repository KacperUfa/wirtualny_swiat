#ifndef WIRTUALNY_SWIAT_TURTLE_H
#define WIRTUALNY_SWIAT_TURTLE_H
#include "Animal.h"

class Turtle: public Animal {
public:
    Turtle(int x, int y, World *world);
    void Draw();
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Action() override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Turtle();
};


#endif //WIRTUALNY_SWIAT_TURTLE_H

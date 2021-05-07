#ifndef WIRTUALNY_SWIAT_TURTLE_H
#define WIRTUALNY_SWIAT_TURTLE_H
#include "Animal.h"

/*
Turtle is quite defensive animal, it is required more than 4 power to kill it, it bounces back the enemy if it is weaker.
Unfortunately it has only 25% chance to move in it's action
 */

class Turtle: public Animal {
public:
    Turtle(int x, int y, World *world);
    void Draw();
    void SayName() override;
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Action() override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Turtle();
};


#endif //WIRTUALNY_SWIAT_TURTLE_H

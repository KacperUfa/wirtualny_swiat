#ifndef WIRTUALNY_SWIAT_HUMAN_H
#define WIRTUALNY_SWIAT_HUMAN_H
#include "Animal.h"

/*
Human is controlled by player, who decides in which direction to move or to use special ability, which is increasing
power of itself
 */

class Human: public Animal {
private:
    int countSpecial;
    bool canActivate;
public:
    Human(int x, int y, World *world);
    void Draw();
    void SayName() override;
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Action() override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Human();
};


#endif //WIRTUALNY_SWIAT_HUMAN_H

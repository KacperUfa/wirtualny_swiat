#ifndef WIRTUALNY_SWIAT_ANIMAL_H
#define WIRTUALNY_SWIAT_ANIMAL_H

#include "Organism.h"


class Animal: public Organism {
private:
public:
    Animal(int power, int initiative, int x, int y, World *world);
    virtual void Draw ()=0;
    virtual bool checkSpecies(Organism* organismTmp);
    Position* Breed(Organism* organismTmp);
    virtual void newAnimal(Position* position);
    void Collision (Organism* org, int x, int y, Position position);
    void Action ();

    ~Animal();

};


#endif //WIRTUALNY_SWIAT_ANIMAL_H

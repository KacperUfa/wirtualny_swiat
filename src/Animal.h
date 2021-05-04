#ifndef WIRTUALNY_SWIAT_ANIMAL_H
#define WIRTUALNY_SWIAT_ANIMAL_H

#include "Organism.h"


class Animal: public Organism {
private:
public:
    Animal(int power, int initiative, int x, int y, World *world);
    void Draw ();
    void Collision ();
    void Action ();

    ~Animal();

};


#endif //WIRTUALNY_SWIAT_ANIMAL_H

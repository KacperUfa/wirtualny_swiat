#ifndef WIRTUALNY_SWIAT_ANIMAL_H
#define WIRTUALNY_SWIAT_ANIMAL_H
#include "Organism.h"

class Animal: public Organism {
private:
public:
    Animal();
    void draw () override;
    void collision () override;
    void action () override;

    ~Animal() override;

};


#endif //WIRTUALNY_SWIAT_ANIMAL_H

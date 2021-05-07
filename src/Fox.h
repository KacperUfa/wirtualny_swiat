#ifndef WIRTUALNY_SWIAT_FOX_H
#define WIRTUALNY_SWIAT_FOX_H


#include "Animal.h"

class Fox : public Animal {
private:

public:
    Fox(int x, int y, World *world);
    void Draw();
    void SayName() override;
    void newAnimal(Position* positionXY) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Action () override;
    ~Fox();
};


#endif //WIRTUALNY_SWIAT_FOX_H

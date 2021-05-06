#ifndef WIRTUALNY_SWIAT_PLANT_H
#define WIRTUALNY_SWIAT_PLANT_H

#include "Organism.h"


class Plant: public Organism {
private:

public:
    Plant(int power, int x, int y, World *world);
    void Collision(Organism* org, int x, int y, Position position);
    virtual void Draw ()=0;
    void Action();
    virtual void newPlant(Position* position);
    virtual bool checkSpecies(Organism* organismTmp);
    Position* Breed(Organism* organismTmp);
    ~Plant();
};


#endif //WIRTUALNY_SWIAT_PLANT_H

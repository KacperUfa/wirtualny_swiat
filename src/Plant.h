#ifndef WIRTUALNY_SWIAT_PLANT_H
#define WIRTUALNY_SWIAT_PLANT_H

#include "Organism.h"

class Plant: public Organism {
private:

public:
    Plant(int power, int x, int y, World *world);
    void collision() override;
    void draw() override;
    void action() override;
    ~Plant();
};


#endif //WIRTUALNY_SWIAT_PLANT_H

#ifndef WIRTUALNY_SWIAT_GRASS_H
#define WIRTUALNY_SWIAT_GRASS_H
#include "Plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y, World *world);
    void Draw() override;
    ~Grass();
};


#endif //WIRTUALNY_SWIAT_GRASS_H

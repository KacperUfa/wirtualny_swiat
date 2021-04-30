#ifndef WIRTUALNY_SWIAT_SWIAT_H
#define WIRTUALNY_SWIAT_SWIAT_H
#include "Organizm.h"
#include "Position.h"
class Organizm;

class Swiat {
private:
    Organizm *organisms;
    Position mapSize;
public:
    Swiat(Position mapSize, Organizm *organisms);
    void makeTurn();
    void drawWorld();
};


#endif //WIRTUALNY_SWIAT_SWIAT_H

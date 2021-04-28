

#ifndef WIRTUALNY_SWIAT_SWIAT_H
#define WIRTUALNY_SWIAT_SWIAT_H

#include "Organizm.h"

class Swiat {
private:
    Organizm *organizms;
public:
    virtual void makeTurn();
    virtual void drawWorld();
};


#endif //WIRTUALNY_SWIAT_SWIAT_H

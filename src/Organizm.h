#ifndef WIRTUALNY_SWIAT_ORGANIZM_H
#define WIRTUALNY_SWIAT_ORGANIZM_H
#include "Swiat.h"
#include "Position.h"
class Organizm {
protected:
    const int power;
    const int initiative;
    Position position;
    //Swiat *world;
public:
    Organizm(int power, int initiative, int x, int y);
    virtual void action();
    virtual void collision();
    virtual void draw();
    virtual ~Organizm();
};


#endif //WIRTUALNY_SWIAT_ORGANIZM_H
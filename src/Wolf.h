#ifndef WIRTUALNY_SWIAT_WOLF_H
#define WIRTUALNY_SWIAT_WOLF_H
#include "Animal.h"

class Wolf: public Animal {
private:

public:
    Wolf(int x, int y, World *world);
    void Draw();
    ~Wolf();
};


#endif //WIRTUALNY_SWIAT_WOLF_H

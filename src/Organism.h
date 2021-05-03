#ifndef WIRTUALNY_SWIAT_ORGANISM_H
#define WIRTUALNY_SWIAT_ORGANISM_H

#include "World.h"
#include "Position.h"

class Organism {
protected:
    int power;
    int initiative;
    Position position;
    World *world;
public:
    Organism(int power, int initiative, int x, int y, World *world);
    int getPower();
    int getInitiative();
    World* getWorld();
    void setPower(int power);
    void setInitiative(int initiative);
    void setWorld(World* world);
    virtual void action()=0;
    virtual void collision()=0;
    virtual void draw();
    virtual ~Organism();

};


#endif //WIRTUALNY_SWIAT_ORGANISM_H

#ifndef WIRTUALNY_SWIAT_ORGANISM_H
#define WIRTUALNY_SWIAT_ORGANISM_H

#include "World.h"
#include "Position.h"

class Organism {
protected:
    int power;
    int initiative;
    Position position;
    bool alive;
    World *world;
public:
    Organism(int power, int initiative, int x, int y, World *world);
    int GetPower();
    int GetInitiative();
    World* GetWorld();
    void SetPower(int power);
    void SetInitiative(int initiative);
    void Kill();
    void SetWorld(World* world);
    int GetPositionX();
    int GetPositionY();
    bool GetState();
    Position GetPosition();
    void SetPositionX(int x);
    void SetPositionY(int y);
    void Move(int x,int y);
    virtual void Action()=0;
    virtual void Collision(Organism* org, int x, int y, Position position)=0;
    virtual void Draw();
    virtual ~Organism();

};


#endif //WIRTUALNY_SWIAT_ORGANISM_H

#ifndef WIRTUALNY_SWIAT_GUARANA_H
#define WIRTUALNY_SWIAT_GUARANA_H
#include "Plant.h"

class Guarana: public Plant {
public:
    Guarana(int x, int y, World *world);
    void Draw() override;
    void SayName() override;
    void newPlant(Position *position) override;
    bool checkSpecies(Organism* organismTmp) override;
    void Collision(Organism* org, int x, int y, Position position) override;
    ~Guarana();

};


#endif //WIRTUALNY_SWIAT_GUARANA_H

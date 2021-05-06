#ifndef WIRTUALNY_SWIAT_HERACLEMSOSNOWSKYI_H
#define WIRTUALNY_SWIAT_HERACLEMSOSNOWSKYI_H
#include "Plant.h"

class HeraclemSosnowskyi: public Plant {
public:
    HeraclemSosnowskyi(int x, int y, World *world);
    void Draw() override;
    void Action() override;
    void newPlant(Position *position) override;
    bool checkSpecies(Organism* organismTmp) override;
    bool checkIfPlant(Organism* organismTmp);
    void Collision(Organism* org, int x, int y, Position position) override;
    ~HeraclemSosnowskyi();
};


#endif //WIRTUALNY_SWIAT_HERACLEMSOSNOWSKYI_H

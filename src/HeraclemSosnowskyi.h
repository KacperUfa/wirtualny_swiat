#ifndef WIRTUALNY_SWIAT_HERACLEMSOSNOWSKYI_H
#define WIRTUALNY_SWIAT_HERACLEMSOSNOWSKYI_H

#include "Plant.h"
#include <iostream>

/*
Haraclem Sosnowskyi is the most dangerous plant, any animal that eats it dies,
and in it's turn it kills every animal on adjacent field
 */

class HeraclemSosnowskyi : public Plant {
public:
    HeraclemSosnowskyi(int x, int y, World *world);

    void Draw() override;

    void Action() override;

    void SayName() override;

    void newPlant(Position *position) override;

    bool checkSpecies(Organism *organismTmp) override;

    bool checkIfPlant(Organism *organismTmp);

    void Collision(Organism *org, int x, int y, Position position) override;

    std::string GetName();

    ~HeraclemSosnowskyi();
};


#endif //WIRTUALNY_SWIAT_HERACLEMSOSNOWSKYI_H

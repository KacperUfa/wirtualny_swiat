#ifndef WIRTUALNY_SWIAT_WORLD_H
#define WIRTUALNY_SWIAT_WORLD_H
#include <vector>
#include "Position.h"


class Organism;

class World {
private:
    std::vector <Organism*> organisms;
    //Organism *organisms;
    Position mapSize;
    std::vector<std::vector <Organism*>> map;
public:
    World(int x, int y, std::vector <Organism*> organisms);
    void MakeTurn();
    void PlaceOrganisms();
    void SetWorld();
    void DrawWorld();
    void addOrganism(Organism* organismTmp);
    void removeOrganism(Organism* organismTmp);
    std::vector<std::vector <Organism*>> GetMap();
    Organism* GetOrganism(int x, int y);
    Position GetMapSize();
    void Erase(Position position);
    ~World();
};

#include "Organism.h"
#endif //WIRTUALNY_SWIAT_WORLD_H

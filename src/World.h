#ifndef WIRTUALNY_SWIAT_WORLD_H
#define WIRTUALNY_SWIAT_WORLD_H
#include <vector>
#include "Position.h"

/*
The most important class, it represents the whole universe and everything happens in it
*/

class Organism;

class World {
private:
    std::vector <Organism*> organisms;
    std::vector <Organism*> organismsTMP;
    std::vector <Organism*> organismToKill;
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
    void addToKill(Organism* organismTmp);
    void removeOrganism(Organism* organismTmp);
    void removeOrganisms();
    void addOrganisms();
    void remOrganisms();
    void SortOrganisms();
    std::vector<std::vector <Organism*>> GetMap();
    Organism* GetOrganism(int x, int y);
    Position GetMapSize();
    void Erase(Position position);
    ~World();
};

#include "Organism.h"
#endif //WIRTUALNY_SWIAT_WORLD_H

#include "World.h"

World::World(int x, int y, std::vector <Organism> organisms): mapSize(x,y){
    this->organisms=organisms;
    std::vector<std::vector <Organism*>> mapTMP(x,std::vector<Organism*>(y, nullptr));
    this->map=mapTMP;

};
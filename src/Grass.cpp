#include "Grass.h"

Grass::Grass(int x, int y, World *world):Plant(0,x, y, world) {

}

void Grass::Draw() {
    printf("G");
}


bool Grass::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Grass*>(organismTmp) != nullptr;
}

void Grass::newPlant(Position *position){
    int x=position->GetX();
    int y=position->GetY();
    Grass *newPlant = new Grass(x,y, this->world);
    this->world->addOrganism(newPlant);
}

Grass::~Grass() noexcept {

}
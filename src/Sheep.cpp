#include "Sheep.h"

Sheep::Sheep(int x, int y, World *world): Animal(4,4,x,y,world) {

}

void Sheep::Draw() {
    printf("S");
}

bool Sheep::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Sheep*>(organismTmp) != nullptr;
}

void Sheep::newAnimal(Position* positionXY) {
    int x=positionXY->GetX();
    int y=positionXY->GetY();
    Sheep *wolf4 = new Sheep(x,y, this->world);
    this->world->addOrganism(wolf4);
}

Sheep::~Sheep() noexcept {

}
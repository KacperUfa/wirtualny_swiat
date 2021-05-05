#include "Wolf.h"

Wolf::Wolf(int x, int y, World *world): Animal(9,5,x,y,world) {

}

void Wolf::Draw() {
    printf("W");
}

bool Wolf::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Wolf*>(organismTmp) != nullptr;
}

void Wolf::newAnimal(Position* positionXY) {
    int x=positionXY->GetX();
    int y=positionXY->GetY();
    Wolf *newAnimal = new Wolf(x,y, this->world);
    this->world->addOrganism(newAnimal);
}

Wolf::~Wolf() noexcept {

}
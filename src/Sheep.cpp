#include "Sheep.h"
#include <iostream>

Sheep::Sheep(int x, int y, World *world): Animal(4,4,x,y,world) {
    std::cout<<"Created new sheep\n";
}

void Sheep::Draw() {
    printf("S");
}

void Sheep::SayName() {
    std::cout<<"Sheep ";
}

bool Sheep::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Sheep*>(organismTmp) != nullptr;
}

void Sheep::newAnimal(Position* positionXY) {
    int x=positionXY->GetX();
    int y=positionXY->GetY();
    Sheep *newAnimal = new Sheep(x,y, this->world);
    this->world->addOrganism(newAnimal);
}

Sheep::~Sheep() noexcept {

}
#include "Wolf.h"
#include <iostream>

Wolf::Wolf(int x, int y, World *world) : Animal(9, 5, x, y, world) {
    std::cout << "Created new wolf\n";
}

void Wolf::Draw() {
    printf("W");
}

bool Wolf::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Wolf *>(organismTmp) != nullptr;
}

void Wolf::newAnimal(Position *positionXY) {
    int x = positionXY->GetX();
    int y = positionXY->GetY();
    Wolf *newAnimal = new Wolf(x, y, this->world);
    this->world->addOrganism(newAnimal);
}

void Wolf::SayName() {
    std::cout << "Wolf ";
}

std::string Wolf::GetName() {
    return "Wolf";
}

Wolf::~Wolf() noexcept {
    this->SayName();
    std::cout << "is dead\n";
}
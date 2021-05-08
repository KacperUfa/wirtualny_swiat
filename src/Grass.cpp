#include "Grass.h"
#include <iostream>

Grass::Grass(int x, int y, World *world) : Plant(0, x, y, world) {
    std::cout << "Created new grass\n";
}

void Grass::Draw() {
    printf("M");
}

void Grass::SayName() {
    std::cout << "Grass ";
}

bool Grass::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Grass *>(organismTmp) != nullptr;
}

void Grass::newPlant(Position *position) {
    int x = position->GetX();
    int y = position->GetY();
    Grass *newPlant = new Grass(x, y, this->world);
    this->world->addOrganism(newPlant);
}

std::string Grass::GetName() {
    return "Grass";
}

Grass::~Grass() noexcept {

}
#include "Sheep.h"

Sheep::Sheep(int x, int y, World *world): Animal(4,4,x,y,world) {

}

void Sheep::Draw() {
    printf("S");
}

bool Sheep::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Sheep*>(organismTmp) != nullptr;
}

Sheep::~Sheep() noexcept {

}
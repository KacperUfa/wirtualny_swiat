#include "Grass.h"

Grass::Grass(int x, int y, World *world):Plant(0,x, y, world) {

}

void Grass::Draw() {
    printf("G");
}

Grass::~Grass() noexcept {

}
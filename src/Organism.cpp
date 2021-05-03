#include "Organism.h"

Organism::Organism(int power, int initiative, int x, int y, World *world) :power(power), initiative(initiative),
position(x, y), world(world) {

}

int Organism::getPower() {
    return this->power;
}

int Organism::getInitiative() {
    return this->initiative;
}

World* Organism::getWorld() {
    return this->world;
}

void Organism::setPower(int power){
    this->power=power;
}

void Organism::setInitiative(int initiative){
    this->initiative=initiative;
}

void Organism::setWorld(World* world){
    this->world=world;
}

void Organism::draw() {
    printf(".");
}

Organism::~Organism() {

}

#include "Organism.h"
#include <iostream>

Organism::Organism(int power, int initiative, int x, int y, World *world) : power(power), initiative(initiative),
                                                                            position(x, y), world(world), alive(true) {

}

int Organism::GetPositionX() {
    return this->position.GetX();
}

Position Organism::GetPosition() {
    return this->position;
}

//checks if the organism is alive, so it can make action
bool Organism::GetState() {
    return this->alive;
}

int Organism::GetPositionY() {
    return this->position.GetY();
}

void Organism::SetPositionX(int x) {
    this->position.SetX(x);
}

void Organism::Kill() {
    this->alive = false;
}

void Organism::SetPositionY(int y) {
    this->position.SetX(y);
}

//changes the coordinates of organism
void Organism::Move(int x, int y) {
    this->position.Move(x, y);
}

int Organism::GetPower() {
    return this->power;
}

int Organism::GetInitiative() {
    return this->initiative;
}

World *Organism::GetWorld() {
    return this->world;
}

void Organism::SetPower(int power) {
    this->power = power;
}

void Organism::SetInitiative(int initiative) {
    this->initiative = initiative;
}

void Organism::SetWorld(World *world) {
    this->world = world;
}

//Draws a sign assigned to class
void Organism::Draw() {
    printf(".");
}

Organism::~Organism() {

}

#include "Guarana.h"
#include <iostream>

Guarana::Guarana(int x, int y, World *world) : Plant(0, x, y, world) {
    std::cout << "Created new guarana\n";
}

void Guarana::Draw() {
    printf("G");
}

void Guarana::SayName() {
    std::cout << "Guarana ";
}

bool Guarana::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Guarana *>(organismTmp) != nullptr;
}

void Guarana::Collision(Organism *org, int x, int y, Position position) {
    this->SayName();
    std::cout << "was eaten by ";
    org->SayName();
    std::cout << "\n";
    this->GetWorld()->addToKill(this);
    this->Kill();
    this->GetWorld()->Erase(this->GetPosition());
    org->Move(x, y);
    org->GetWorld()->Erase(position);
    org->SetPower(org->GetPower() + 3);
}

void Guarana::newPlant(Position *position) {
    int x = position->GetX();
    int y = position->GetY();
    Guarana *newPlant = new Guarana(x, y, this->world);
    this->world->addOrganism(newPlant);
}

std::string Guarana::GetName() {
    return "Guarana";
}

Guarana::~Guarana() noexcept {
    this->SayName();
    std::cout << "is dead\n";
}
#include "Guarana.h"

Guarana::Guarana(int x, int y, World *world):Plant(0,x, y, world) {

}

void Guarana::Draw() {
    printf("G");
}


bool Guarana::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Guarana*>(organismTmp) != nullptr;
}

void Guarana::Collision(Organism *org, int x, int y, Position position) {
    this->GetWorld()->addToKill(this);
    this->Kill();
    this->GetWorld()->Erase(this->GetPosition());
    org->Move(x,y);
    org->GetWorld()->Erase(position);
    org->SetPower(org->GetPower()+3);
}

void Guarana::newPlant(Position *position){
    int x=position->GetX();
    int y=position->GetY();
    Guarana *newPlant = new Guarana(x,y, this->world);
    this->world->addOrganism(newPlant);
}

Guarana::~Guarana() noexcept {

}
#include "Nightshade.h"
#include <iostream>

Nightshade::Nightshade(int x, int y, World *world):Plant(99,x, y, world) {
    std::cout<<"Created new nightshade\n";
}

void Nightshade::Draw() {
    printf("N");
}

void Nightshade::SayName() {
    std::cout<<"Nightshade ";
}

bool Nightshade::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Nightshade*>(organismTmp) != nullptr;
}

void Nightshade::Collision(Organism *org, int x, int y, Position position) {
    this->SayName();
    std::cout<<"was eaten by ";
    org->SayName();
    std::cout<<"\n";
    this->SayName();
    std::cout<<"killed ";
    org->SayName();
    std::cout<<"\n";
    this->GetWorld()->addToKill(this);
    org->GetWorld()->addToKill(org);
    this->Kill();
    org->Kill();
    this->GetWorld()->Erase(this->GetPosition());
    org->GetWorld()->Erase(org->GetPosition());
}

void Nightshade::newPlant(Position *position){
    int x=position->GetX();
    int y=position->GetY();
    Nightshade *newPlant = new Nightshade(x,y, this->world);
    this->world->addOrganism(newPlant);
}

Nightshade::~Nightshade() noexcept {

}
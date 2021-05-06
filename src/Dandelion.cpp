#include "Dandelion.h"

Dandelion::Dandelion(int x, int y, World *world):Plant(0,x, y, world) {

}

void Dandelion::Draw() {
    printf("D");
}

void Dandelion::Action() {
    for(int i=0;i<3;i++){
        int spread=(rand()%8)+1;
        if(spread==1){
            Position plantPosition = this->position;
            Position worldMap=this->world->GetMapSize();

            Position* breedPosition = this->Breed(this);
            if(breedPosition!= nullptr){
                this->newPlant(breedPosition);
            }
        }
    }
}

bool Dandelion::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Dandelion*>(organismTmp) != nullptr;
}

void Dandelion::newPlant(Position *position){
    int x=position->GetX();
    int y=position->GetY();
    Dandelion *newPlant = new Dandelion(x,y, this->world);
    this->world->addOrganism(newPlant);
}

Dandelion::~Dandelion() noexcept {

}

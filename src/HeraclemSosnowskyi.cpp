#include "HeraclemSosnowskyi.h"
#include <iostream>

HeraclemSosnowskyi::HeraclemSosnowskyi(int x, int y, World *world):Plant(10,x, y, world) {

}

void HeraclemSosnowskyi::Draw() {
    printf("H");
}


bool HeraclemSosnowskyi::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<HeraclemSosnowskyi*>(organismTmp) != nullptr;
}

bool HeraclemSosnowskyi::checkIfPlant(Organism *organismTmp) {
    return dynamic_cast<Plant*>(organismTmp) != nullptr;
}

void HeraclemSosnowskyi::Action() {
    int spread = (rand() % 8) + 1;
    if (spread == 1) {
        Position plantPosition = this->position;
        Position worldMap = this->world->GetMapSize();

        Position *breedPosition = this->Breed(this);
        if (breedPosition != nullptr) {
            this->newPlant(breedPosition);
        }
    }
    for (int i = -1; i < 2; i++) {
        int currentOrganismPosX = this->GetPositionX();
        int currentOrganismPosY = this->GetPositionY();
        if ((currentOrganismPosX + i) < 0 || (currentOrganismPosX + i) > (GetWorld()->GetMapSize().GetY() - 1)) {
            continue;
        }
        for (int j = -1; j < 2; j++) {
            if ((currentOrganismPosY + j) < 0 ||
                (currentOrganismPosY + j) > (GetWorld()->GetMapSize().GetX() - 1)) {
                continue;
            }
            if (this->world->GetOrganism((currentOrganismPosX + i), (currentOrganismPosY + j)) != nullptr) {

                Organism* orgTMP = this->world->GetOrganism((currentOrganismPosX + i), (currentOrganismPosY + j));

                if(!(this->checkIfPlant(orgTMP))){
                    orgTMP->GetWorld()->addToKill(orgTMP);
                    orgTMP->Kill();
                    orgTMP->GetWorld()->Erase(orgTMP->GetPosition());
                }
            }
        }
    }
}

void HeraclemSosnowskyi::Collision(Organism *org, int x, int y, Position position) {
    this->GetWorld()->addToKill(this);
    org->GetWorld()->addToKill(org);
    this->Kill();
    org->Kill();
    this->GetWorld()->Erase(this->GetPosition());
    org->GetWorld()->Erase(org->GetPosition());
    std::cout<<"zabity zostal\n";
}

void HeraclemSosnowskyi::newPlant(Position *position){
    int x=position->GetX();
    int y=position->GetY();
    HeraclemSosnowskyi *newPlant = new HeraclemSosnowskyi(x,y, this->world);
    this->world->addOrganism(newPlant);
}

HeraclemSosnowskyi::~HeraclemSosnowskyi() noexcept {

}
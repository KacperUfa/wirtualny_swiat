#include "Dandelion.h"

Dandelion::Dandelion(int x, int y, World *world):Plant(0,x, y, world) {

}

void Dandelion::Draw() {
    printf("D");
}

void Dandelion::Action() {
    for(int i=0;i<3;i++){


        int spread=(rand()%10)+1;
        if(spread==1 || spread==2) {

            /*
                Position plantPosition = this->position;
                Position worldMap=this->world->GetMapSize();

                Position* breedPosition = this->Breed(this);
                if(breedPosition!= nullptr){
                    this->newPlant(breedPosition);
                }
                */

            int x, y;
            int actualX = this->position.GetX();
            int actualY = this->position.GetY();
            Position plantPosition = this->position;
            Position worldMap = this->world->GetMapSize();

            do {
                x = (rand() % 3) - 1;
                y = (rand() % 3) - 1;

            } while (x == 0 && y == 0);

            if (actualX == 0 && x < 0) {
                x = 1;
            } else if (actualX == worldMap.GetX() - 1 && x > 0) {
                x = -1;
            }
            if (actualY == 0 && y < 0) {
                y = 1;
            } else if (actualY == worldMap.GetY() - 1 && y > 0) {
                y = -1;
            }

            Organism *tmpOrg = this->world->GetOrganism(actualX + x, actualY + y);

            if (tmpOrg == nullptr) {
                Position *newPosition = new Position(actualX + x, actualY + y);
                this->newPlant(newPosition);
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

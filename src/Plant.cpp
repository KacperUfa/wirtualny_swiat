#include "Plant.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

Plant::Plant(int power, int x, int y, World *world) : Organism(power, 0, x, y, world) {

}

//basic action for spreading seeds by plants
void Plant::Action() {

    int spread = (rand() % 10) + 1;
    if (spread == 1 || spread == 2) {
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
        } else if (actualX == worldMap.GetY() - 1 && x > 0) {
            x = -1;
        }
        if (actualY == 0 && y < 0) {
            y = 1;
        } else if (actualY == worldMap.GetX() - 1 && y > 0) {
            y = -1;
        }

        Organism *tmpOrg = this->world->GetOrganism(actualX + x, actualY + y);

        if (tmpOrg == nullptr) {
            this->SayName();
            std::cout << "propageted\n";
            Position *newPosition = new Position(actualX + x, actualY + y);
            this->newPlant(newPosition);
        }


    }
}

bool Plant::checkSpecies(Organism *organismTmp) {
    return false;
}

void Plant::newPlant(Position *position) {}

//basic collision in which it is eaten by animal
void Plant::Collision(Organism *org, int x, int y, Position position) {
    this->SayName();
    std::cout << "was eaten by ";
    org->SayName();
    std::cout << "\n";
    this->GetWorld()->addToKill(this);
    this->Kill();
    this->GetWorld()->Erase(this->GetPosition());
    org->Move(x, y);
    org->GetWorld()->Erase(position);
}

//estimating free adjacent field
Position *Plant::Breed(Organism *organismTmp) {
    for (int i = -1; i < 2; i++) {
        int currentOrganismPosX = organismTmp->GetPositionX();
        int currentOrganismPosY = organismTmp->GetPositionY();
        if ((currentOrganismPosX + i) < 0 || (currentOrganismPosX + i) > (GetWorld()->GetMapSize().GetY() - 1)) {
            continue;
        }
        for (int j = -1; j < 2; j++) {
            if ((currentOrganismPosY + j) < 0 || (currentOrganismPosY + j) > (GetWorld()->GetMapSize().GetX() - 1)) {
                continue;
            }
            if (this->world->GetOrganism((currentOrganismPosX + i), (currentOrganismPosY + j)) == nullptr) {
                Position *newPosition = new Position((currentOrganismPosX + i), (currentOrganismPosY + j));
                return newPosition;
            };
        }
    }
    return nullptr;
}

Plant::~Plant() noexcept {

}
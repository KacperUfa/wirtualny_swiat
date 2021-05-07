#include "HeraclemSosnowskyi.h"
#include <iostream>

HeraclemSosnowskyi::HeraclemSosnowskyi(int x, int y, World *world) : Plant(10, x, y, world) {
    std::cout << "Created new Heraclem Sosnowskyi\n";
}

void HeraclemSosnowskyi::Draw() {
    printf("H");
}


bool HeraclemSosnowskyi::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<HeraclemSosnowskyi *>(organismTmp) != nullptr;
}

bool HeraclemSosnowskyi::checkIfPlant(Organism *organismTmp) {
    return dynamic_cast<Plant *>(organismTmp) != nullptr;
}

void HeraclemSosnowskyi::Action() {
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

                Organism *orgTMP = this->world->GetOrganism((currentOrganismPosX + i), (currentOrganismPosY + j));

                if (!(this->checkIfPlant(orgTMP))) {
                    this->SayName();
                    std::cout << "killed ";
                    orgTMP->SayName();
                    std::cout << "\n";
                    orgTMP->GetWorld()->addToKill(orgTMP);
                    orgTMP->Kill();
                    orgTMP->GetWorld()->Erase(orgTMP->GetPosition());
                }
            }
        }
    }
}

void HeraclemSosnowskyi::Collision(Organism *org, int x, int y, Position position) {
    this->SayName();
    std::cout << "was eaten by ";
    org->SayName();
    std::cout << "\n";
    this->SayName();
    std::cout << "killed ";
    org->SayName();
    std::cout << "\n";
    this->GetWorld()->addToKill(this);
    org->GetWorld()->addToKill(org);
    this->Kill();
    org->Kill();
    this->GetWorld()->Erase(this->GetPosition());
    org->GetWorld()->Erase(org->GetPosition());
    std::cout << "zabity zostal\n";
}

void HeraclemSosnowskyi::SayName() {
    std::cout << "Heraclem Sosnowskyi ";
}

void HeraclemSosnowskyi::newPlant(Position *position) {
    int x = position->GetX();
    int y = position->GetY();
    HeraclemSosnowskyi *newPlant = new HeraclemSosnowskyi(x, y, this->world);
    this->world->addOrganism(newPlant);
}

HeraclemSosnowskyi::~HeraclemSosnowskyi() noexcept {

}
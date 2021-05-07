#include <iostream>
#include "Fox.h"

Fox::Fox(int x, int y, World *world) : Animal(3, 7, x, y, world) {
    std::cout << "Created new fox\n";
}

void Fox::Draw() {
    printf("F");
}

bool Fox::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Fox *>(organismTmp) != nullptr;
}

void Fox::newAnimal(Position *positionXY) {
    int x = positionXY->GetX();
    int y = positionXY->GetY();
    Fox *newAnimal = new Fox(x, y, this->world);
    this->world->addOrganism(newAnimal);
}

//Fox action differs from basic animal, because he won't go to the field with stronger animal
void Fox::Action() {
    int x, y;
    int actualX = this->position.GetX();
    int actualY = this->position.GetY();
    Position animalPosition = this->position;
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
        this->position.Move(x, y);
        this->world->Erase(animalPosition);
        this->SayName();
        std::cout << "moved\n";
    } else {
        if (tmpOrg->GetPower() <= this->power) {
            tmpOrg->Collision(this, x, y, animalPosition);
        } else {
            this->SayName();
            std::cout << "stopped from moving\n";
        }
    }
}

void Fox::SayName() {
    std::cout << "Fox ";
}

Fox::~Fox() noexcept {
    this->SayName();
    std::cout << "is dead\n";
}
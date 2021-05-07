#include "Antelope.h"
#include <iostream>

Antelope::Antelope(int x, int y, World *world) : Animal(4, 4, x, y, world) {
    std::cout << "Created new antelope\n";
}

void Antelope::Draw() {
    printf("A");
}

void Antelope::Action() {
    int x, y;
    int actualX = this->position.GetX();
    int actualY = this->position.GetY();
    Position animalPosition = this->position;
    Position worldMap = this->world->GetMapSize();

    do {
        x = (rand() % 3) - 1;
        y = (rand() % 3) - 1;

    } while (x == 0 && y == 0);

    x *= 2;
    y *= 2;

    if ((actualX == 0 || actualX == 1) && x < 0) {
        x = 2;
    } else if ((actualX == worldMap.GetY() - 1 || actualX == worldMap.GetY() - 2) && x > 0) {
        x = -2;
    }
    if ((actualY == 0 || actualY == 1) && y < 0) {
        y = 2;
    } else if ((actualY == worldMap.GetX() - 1 || actualY == worldMap.GetX() - 2) && y > 0) {
        y = -2;
    }

    Organism *tmpOrg = this->world->GetOrganism(actualX + x, actualY + y);

    if (tmpOrg == nullptr) {
        this->position.Move(x, y);
        this->world->Erase(animalPosition);
        this->SayName();
        std::cout << "moved\n";
    } else {
        tmpOrg->Collision(this, x, y, animalPosition);
    }

}

void Antelope::SayName() {
    std::cout << "Antelope ";
}

void Antelope::Collision(Organism *tmpOrg, int x, int y, Position position) {
    if (tmpOrg->checkSpecies(this)) {

        //kopulacja
        Position *breedPosition = tmpOrg->Breed(this);
        if (breedPosition != nullptr) {
            newAnimal(breedPosition);
            this->SayName();
            std::cout << "multiplied\n";
        } else {
            this->SayName();
            std::cout << "tried to multiply\n";
        }
    } else {
        //walka
        int randomise = (rand() % 2) + 1;
        if (randomise == 1 && this->Breed(this) != nullptr) {
            Position *escapePosition = Breed(this);
            this->Move(escapePosition);
            tmpOrg->GetWorld()->Erase(this->GetPosition());
            tmpOrg->Move(x, y);
            tmpOrg->GetWorld()->Erase(position);
            this->SayName();
            std::cout << "escaped\n";
        } else {
            if (tmpOrg->GetPower() >= this->power) {
                tmpOrg->SayName();
                std::cout << "killed ";
                this->SayName();
                std::cout << "\n";
                this->Kill();
                this->GetWorld()->addToKill(this);
                tmpOrg->Move(x, y);
                tmpOrg->GetWorld()->Erase(this->GetPosition());
                tmpOrg->GetWorld()->Erase(position);

            } else {
                tmpOrg->SayName();
                std::cout << "killed itself by attacking ";
                this->SayName();
                std::cout << "\n";
                tmpOrg->GetWorld()->addToKill(tmpOrg);
                tmpOrg->Kill();
                tmpOrg->GetWorld()->Erase(position);
            }
        }
    }
}

bool Antelope::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Antelope *>(organismTmp) != nullptr;
}

void Antelope::newAnimal(Position *positionXY) {
    int x = positionXY->GetX();
    int y = positionXY->GetY();
    Antelope *newAnimal = new Antelope(x, y, this->world);
    this->world->addOrganism(newAnimal);
}

std::string Antelope::GetName() {
    return "Antelope";
}

Antelope::~Antelope() noexcept {

}

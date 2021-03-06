#include "Human.h"
#include <iostream>

Human::Human(int x, int y, World *world) : Animal(5, 4, x, y, world) {
    this->countSpecial = 0;
    std::cout << "Created new human\n";
}

void Human::Draw() {
    printf("O");
}


void Human::SetActivate(bool x) {
    this->canActivate = x;
}

void Human::SetSpecial(int x) {
    this->countSpecial = x;
}

void Human::Action() {
    if (this->canActivate == false) {
        this->countSpecial--;
        if (this->countSpecial == 0) {
            this->canActivate = true;
        } else if (this->countSpecial > 4) {
            this->power--;
        }

    }
    int x = 0;
    int y = 0;
    int actualX = this->position.GetX();
    int actualY = this->position.GetY();
    Position animalPosition = this->position;
    Position worldMap = this->world->GetMapSize();
    char cmd;
    bool haveNotChosen = true;

    while (haveNotChosen) {
        std::cout << "\n";
        std::cout << "       w\n";
        std::cout << "       ^\n";
        std::cout << "       |\n";
        std::cout << "a<-----+----->d\n";
        std::cout << "       |\n";
        std::cout << "       |\n";
        std::cout << "       s\n\n";
        std::cout << " -------------\n";
        std::cout << "|   ability   |\n";
        std::cout << "|      Q      |\n";
        std::cout << " -------------\n";
        std::cin >> cmd;

        switch (cmd) {
            case 'a':
                x = -1;
                haveNotChosen = false;
                break;
            case 'w':
                y = -1;
                haveNotChosen = false;
                break;
            case 's':
                y = 1;
                haveNotChosen = false;
                break;
            case 'd':
                x = 1;
                haveNotChosen = false;
                break;
            case 'q':
                if (canActivate) {
                    this->power += 5;
                    this->countSpecial = 10;
                    this->canActivate = false;
                    this->SayName();
                    std::cout << "activated special ability\n";
                    haveNotChosen = false;
                } else {
                    std::cout << "It is not ready\n";
                }
                break;
            default:
                break;
        }
    }

    if (actualX == 0 && x < 0) {
        x = 0;
    } else if (actualX == worldMap.GetY() - 1 && x > 0) {
        x = 0;
    }
    if (actualY == 0 && y < 0) {
        y = 0;
    } else if (actualY == worldMap.GetX() - 1 && y > 0) {
        y = -0;
    }
    if (!(x == 0 && y == 0)) {
        Organism *tmpOrg = this->world->GetOrganism(actualX + x, actualY + y);

        if (tmpOrg == nullptr) {
            this->position.Move(x, y);
            this->world->Erase(animalPosition);
            this->SayName();
            std::cout << "moved\n";
        } else {
            tmpOrg->Collision(this, x, y, animalPosition);
        }
    } else {
        this->SayName();
        std::cout << "did not move\n";
    }
}

void Human::SayName() {
    std::cout << "Human ";
}

void Human::Collision(Organism *tmpOrg, int x, int y, Position position) {
    if (tmpOrg->checkSpecies(this)) {

        //kopiulacja
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
        if (tmpOrg->GetPower() >= this->power) {
            tmpOrg->SayName();
            std::cout << "killed ";
            this->SayName();
            std::cout << "\n";
            this->Kill();
            this->GetWorld()->addToKill(this);
            tmpOrg->GetWorld()->Erase(this->GetPosition());
            tmpOrg->Move(x, y);
            //tmpOrg->GetWorld()->Erase(this->GetPosition());
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

bool Human::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Human *>(organismTmp) != nullptr;
}

void Human::newAnimal(Position *positionXY) {
    int x = positionXY->GetX();
    int y = positionXY->GetY();
    Human *newAnimal = new Human(x, y, this->world);
    this->world->addOrganism(newAnimal);
}

std::string Human::GetName() {
    return "Human";
}

std::string Human::GetActivate() {
    if (this->canActivate) {
        return "true";
    } else {
        return "false";
    }
}

int Human::GetSpecial() {
    return this->countSpecial;
}

Human::~Human() {
    this->SayName();
    std::cout << "is dead\n";
}
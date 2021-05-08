#include "World.h"
#include <iostream>

World::World(int x, int y, std::vector<Organism *> organisms) : mapSize(y, x) {
    this->organisms = organisms;
    std::vector<std::vector<Organism *>> mapTMP(y, std::vector<Organism *>(x, nullptr));
    this->map = mapTMP;
    this->SetWorld();
    this->PlaceOrganisms();
    std::cout << "Created new world\n";
}

const std::vector<Organism *> &World::getOrganisms() const {
    return organisms;
};

//Drawing in console the entire world with all organisms in it
void World::DrawWorld() {
    printf("\n");
    for (int i = 0; i < this->mapSize.GetX(); i++) {
        for (int j = 0; j < this->mapSize.GetY(); j++) {
            if (this->map[i][j] != nullptr) {
                this->map[i][j]->Draw();
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Making Action() of all the alive organisms
void World::MakeTurn() {
    for (auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++) {
        if ((*iter)->GetState()) {
            (*iter)->Action();
            if ((*iter)->GetState()) {
                int x = (*iter)->GetPositionX();
                int y = (*iter)->GetPositionY();
                this->map[y][x] = *iter;
            }
        }
    }
    this->DrawWorld();
}

//function to add organism to temporary vector with organisms to delete from main list
void World::addToKill(Organism *organismTmp) {
    this->organismToKill.push_back(organismTmp);
}

//adding all organisms to main vector
void World::addOrganisms() {
    while (this->organismsTMP.size() > 0) {
        this->organisms.push_back(this->organismsTMP.back());
        this->organismsTMP.pop_back();
    }
}

//function setting the world pointer of the all organisms in it to this world
void World::SetWorld() {
    for (auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++) {
        (*iter)->SetWorld(this);
    }
}

Position World::GetMapSize() {
    return this->mapSize;
}

//remove organism from main vector
void World::removeOrganism(Organism *organismTmp) {
    auto newEnd = std::remove(this->organisms.begin(), this->organisms.end(), organismTmp);
    this->organisms.erase(newEnd, this->organisms.end());
    delete organismTmp;
}

//remove all organism from main vector
void World::removeOrganisms() {
    for (auto iter = this->organismToKill.begin(); iter != this->organismToKill.end(); iter++) {
        removeOrganism(*iter);
    }
}

//placing all organism from the main vector on the map
void World::PlaceOrganisms() {
    for (auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++) {

        int x = (*iter)->GetPositionX();
        int y = (*iter)->GetPositionY();
        this->map[y][x] = *iter;
    }
}

//function to add organism to temporary vector with organisms to add to the main list and to the map
void World::addOrganism(Organism *organismTmp) {
    this->organismsTMP.push_back(organismTmp);
    int x = organismTmp->GetPositionX();
    int y = organismTmp->GetPositionY();
    this->map[y][x] = organismTmp;
}

std::vector<std::vector<Organism *>> World::GetMap() {
    return this->map;
}

Organism *World::GetOrganism(int x, int y) {
    return this->map[y][x];
}

//sorting all of the listed organisms by their initiative
void World::SortOrganisms() {
    std::vector<Organism *> organismsTMP;
    for (int i = 7; i >= 0; i--) {
        for (auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++) {
            if ((*iter)->GetInitiative() == i) {
                organismsTMP.push_back((*iter));
            }
        }
    }
    this->organisms = organismsTMP;
}

//erasing the existence of the organism from the map
void World::Erase(Position position) {
    map[position.GetY()][position.GetX()] = nullptr;
}

World::~World() {
    std::cout << "THE END IS COMING!";
}
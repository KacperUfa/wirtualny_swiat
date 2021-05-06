#include "World.h"
#include <iostream>

World::World(int x, int y, std::vector <Organism*> organisms): mapSize(y,x){
    this->organisms=organisms;
    std::vector<std::vector <Organism*>> mapTMP(y,std::vector<Organism*>(x, nullptr));
    this->map=mapTMP;
    this->SetWorld();
    this->PlaceOrganisms();

};

void World::DrawWorld() {
    for(int i=0;i<this->mapSize.GetX();i++){
        for(int j=0;j<this->mapSize.GetY();j++){
            if(this->map[i][j]!= nullptr) {
                this->map[i][j]->Draw();
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void World::MakeTurn() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){
        if((*iter)->GetState()){
            (*iter)->Action();
            if((*iter)->GetState()){
                int x=(*iter)->GetPositionX();
                int y=(*iter)->GetPositionY();
                this->map[y][x]=*iter;
            }

        }

    }
    this->DrawWorld();
}

void World::addToKill(Organism *organismTmp) {
    this->organismToKill.push_back(organismTmp);
}

void World::addOrganisms() {
    while (this->organismsTMP.size()>0){
        this->organisms.push_back(this->organismsTMP.back());
        this->organismsTMP.pop_back();
    }
}

void World::SetWorld() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){
        (*iter)->SetWorld(this);
    }
}

Position World::GetMapSize() {
    return this->mapSize;
}

void World::removeOrganism(Organism* organismTmp) {
    auto newEnd = std::remove(this->organisms.begin(),this->organisms.end(), organismTmp);
    this->organisms.erase(newEnd, this->organisms.end());
}

void World::removeOrganisms() {
    for(auto iter = this->organismToKill.begin(); iter != this->organismToKill.end(); iter++){
        removeOrganism(*iter);
    }

}

void World::PlaceOrganisms() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){

        int x=(*iter)->GetPositionX();
        int y=(*iter)->GetPositionY();
        this->map[y][x]=*iter;
    }
}

void World::addOrganism(Organism *organismTmp) {
    this->organismsTMP.push_back(organismTmp);
    int x=organismTmp->GetPositionX();
    int y=organismTmp->GetPositionY();
    this->map[y][x]=organismTmp;
}

std::vector<std::vector <Organism*>> World::GetMap(){
    return this->map;
}

Organism* World::GetOrganism(int x, int y) {
    return this->map[y][x];
}

void World::Erase(Position position) {
    map[position.GetY()][position.GetX()]= nullptr;
}
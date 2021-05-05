#include "World.h"
#include <iostream>

World::World(int x, int y, std::vector <Organism*> organisms): mapSize(x,y){
    this->organisms=organisms;
    //std::vector <Organism*> organisms

    std::vector<std::vector <Organism*>> mapTMP(x,std::vector<Organism*>(y, nullptr));
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
        (*iter)->Action();
        int x=(*iter)->GetPositionX();
        int y=(*iter)->GetPositionY();
        this->map[x][y]=*iter;
    }
    this->DrawWorld();

}

void World::addOrganisms() {
    /*if(organismsTMP.size()>0){
        for(auto iter = this->organismsTMP.begin(); iter != this->organismsTMP.end(); iter++){
            this->organisms.push_back(*iter);
        }
    }*/
    while (this->organismsTMP.size()>0){
        this->organisms.push_back(this->organismsTMP.front());
        this->organismsTMP.pop_back();
    }

}

void World::remOrganisms() {
    while (organismsTMP.size()>0){
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

void World::PlaceOrganisms() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){

        int x=(*iter)->GetPositionX();
        int y=(*iter)->GetPositionY();
        this->map[x][y]=*iter;
    }
}

void World::addOrganism(Organism *organismTmp) {
    this->organismsTMP.push_back(organismTmp);
    int x=organismTmp->GetPositionX();
    int y=organismTmp->GetPositionY();
    this->map[x][y]=organismTmp;
}

std::vector<std::vector <Organism*>> World::GetMap(){
    return this->map;
}

Organism* World::GetOrganism(int x, int y) {
    return this->map[x][y];
}

void World::Erase(Position position) {
    map[position.GetX()][position.GetY()]= nullptr;
}
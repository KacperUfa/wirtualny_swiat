#include "World.h"

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
        printf("%d %d\n",(*iter)->GetPositionX(), (*iter)->GetPositionY());
        //
        int x=(*iter)->GetPositionX();
        int y=(*iter)->GetPositionY();
        this->map[x][y]=*iter;
        //
    }
    //this->PlaceOrganisms();
    this->DrawWorld();
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
    auto newEnd = remove(this->organisms.begin(),this->organisms.end(), organismTmp);
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
    this->organisms.push_back(organismTmp);
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
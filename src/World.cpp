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
}

void World::MakeTurn() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){
        (*iter)->Action();
    }
    this->PlaceOrganisms();
    this->DrawWorld();
}

void World::SetWorld() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){
        (*iter)->SetWorld(this);
    }
}

void World::PlaceOrganisms() {
    for(auto iter = this->organisms.begin(); iter != this->organisms.end(); iter++){

        int x=(*iter)->GetPositionX();
        int y=(*iter)->GetPositionY();
        this->map[x][y]=*iter;
    }
}
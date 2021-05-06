#include "Plant.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

Plant::Plant(int power, int x, int y, World *world): Organism(power,0, x,y,world) {

}

void Plant::Action() {

    int spread=(rand()%1)+1;
    if(spread==1){
        int x, y;
        int actualX=this->position.GetX();
        int actualY=this->position.GetY();
        Position plantPosition = this->position;
        Position worldMap=this->world->GetMapSize();

        Position* breedPosition = this->Breed(this);
        if(breedPosition!= nullptr){
            std::cout<<breedPosition->GetX()<<":"<<breedPosition->GetY()<<std::endl;
            this->newPlant(breedPosition);
        }
/*
        Position* breedPosition=tmpOrg->Breed(this);
        if(breedPosition!= nullptr){
            newAnimal(breedPosition);
        }*/
        // printf("KOPULACJA\n");


    }
}

bool Plant::checkSpecies(Organism *organismTmp) {
    return false;
}

void Plant::newPlant(Position *position) {}

void Plant::Collision(Organism* org, int x, int y, Position position) {

}

Position* Plant::Breed(Organism *organismTmp) {
    for(int i=-1; i<2;i++){
        int currentOrganismPosX = organismTmp->GetPositionX();
        int currentOrganismPosY = organismTmp->GetPositionY();
        if ((currentOrganismPosX + i) < 0 || (currentOrganismPosX + i) > (GetWorld()->GetMapSize().GetX()-1)) {
            std::cout<<"i problem\n";
            continue;
        }
        for(int j=-1;j<2;j++){
            if ((currentOrganismPosY + j) < 0 || (currentOrganismPosY + j) > (GetWorld()->GetMapSize().GetY()-1)) {
                std::cout<<"j problem\n";
                continue;
            }
            if(this->world->GetOrganism((currentOrganismPosX+i),(currentOrganismPosY+j))== nullptr){
                Position* newPosition = new Position((currentOrganismPosX+i),(currentOrganismPosY+j));
                return newPosition;
            };
        }
    }
    std::cout<<"jestes fraJESRT KACPER\n";
    return nullptr;
}

Plant::~Plant() noexcept {

}
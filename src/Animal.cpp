#include "Animal.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

Animal::Animal(int power, int initiative, int x, int y, World *world):Organism(power,initiative,x,y,world) {

}

//basic animal action which is based on moving on the map

void Animal::Action() {
        int x, y;
        int actualX=this->position.GetX();
        int actualY=this->position.GetY();
        Position animalPosition = this->position;
        Position worldMap=this->world->GetMapSize();

        do{
            x=(rand()%3)-1;
            y=(rand()%3)-1;

        }while(x==0 && y ==0);

        if(actualX==0 && x<0){
            x=1;
        }
        else if(actualX== worldMap.GetY()-1 && x>0){
            x=-1;
        }
        if(actualY==0 && y<0){
            y=1;
        }
        else if(actualY== worldMap.GetX()-1 && y>0){
            y=-1;
        }

        Organism* tmpOrg=this->world->GetOrganism(actualX+x,actualY+y);

        if(tmpOrg== nullptr){
            this->position.Move(x,y);
            this->world->Erase(animalPosition);
            this->SayName();
            std::cout<<"moved\n";
        }
        else{
            tmpOrg->Collision(this, x,y,animalPosition);
        }
}

void Animal::Move(int x, int y) {
    this->position.Move(x,y);
}

void Animal::Move(Position *position) {
    this->position=*position;
}

//checking if the other organism is the same species as the organism it is called by
bool Animal::checkSpecies(Organism* organismTmp) {
 return false;
}

//making new object of the same class
void Animal::newAnimal(Position *position) {}

//estimating free adjacent field
Position* Animal::Breed(Organism *organismTmp) {

    for(int i=-1; i<2;i++){
        int currentOrganismPosX = organismTmp->GetPositionX();
        int currentOrganismPosY = organismTmp->GetPositionY();
        if ((currentOrganismPosX + i) < 0 || (currentOrganismPosX + i) > (GetWorld()->GetMapSize().GetY()-1)) {
            continue;
        }
        for(int j=-1;j<2;j++){
            if ((currentOrganismPosY + j) < 0 || (currentOrganismPosY + j) > (GetWorld()->GetMapSize().GetX()-1)) {
                continue;
            }
            if(this->world->GetOrganism((currentOrganismPosX+i),(currentOrganismPosY+j))== nullptr){
                Position* newPosition = new Position((currentOrganismPosX+i),(currentOrganismPosY+j));
                return newPosition;
            };
        }
    }
    return nullptr;
}

//basic collision which is ended with multiplying or fighting with other organism
void Animal::Collision(Organism* tmpOrg, int x, int y, Position animalPosition ) {
    if(tmpOrg->checkSpecies(this)){
        //Breeding part
        Position* breedPosition=tmpOrg->Breed(this);
        if(breedPosition!= nullptr){
            newAnimal(breedPosition);
            this->SayName();
            std::cout<<"multiplied\n";
        }
        else{
            this->SayName();
            std::cout<<"tried to multiply\n";
        }

    }
    else{
        //fighting part
        if(tmpOrg->GetPower()>=this->power){
            tmpOrg->SayName();
            std::cout<<"killed ";
            this->SayName();
            std::cout<<"\n";
            this->Kill();
            this->GetWorld()->addToKill(this);
            tmpOrg->GetWorld()->Erase(this->GetPosition());
            tmpOrg->Move(x,y);
        }
        else{
            tmpOrg->SayName();
            std::cout<<"killed itself by attacking ";
            this->SayName();
            std::cout<<"\n";
            tmpOrg->GetWorld()->addToKill(tmpOrg);
            tmpOrg->Kill();
        }
        tmpOrg->GetWorld()->Erase(animalPosition);
    }
}

Animal::~Animal() noexcept {

}
#include "Animal.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Animal::Animal(int power, int initiative, int x, int y, World *world):Organism(power,initiative,x,y,world) {

}

void Animal::Action() {
    int x, y;
    //srand(time(NULL));
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
    else if(actualX== worldMap.GetX()-1 && x>0){
        x=-1;
    }
    if(actualY==0 && y<0){
        y=1;
    }
    else if(actualY== worldMap.GetY()-1 && y>0){
        y=-1;
    }

    Organism* tmpOrg=this->world->GetOrganism(actualX+x,actualY+y);


    if(tmpOrg== nullptr){
        this->position.Move(x,y);
        this->world->Erase(animalPosition);
    }
    else{
        if(this->checkSpecies(tmpOrg)){
            //kopiulacja
            Position* breedPosition=this->Breed(tmpOrg);
            if(breedPosition!= nullptr){
                newAnimal(breedPosition);
            }
            //
            printf("KOPULACJA\n");
        }
        else{
            //walka
            if(this->power>=tmpOrg->GetPower()){
                this->world->removeOrganism(tmpOrg);
                this->position.Move(x,y);
                this->world->Erase(animalPosition);
            }
            else{
                this->world->removeOrganism(this);
                this->world->Erase(animalPosition);
            }
            printf("WALKA\n");
        }

    }

}

bool Animal::checkSpecies(Organism* organismTmp) {
 return false;
}

void Animal::newAnimal(Position *position) {}

Position* Animal::Breed(Organism *organismTmp) {
    for(int i=-1; i<2;i++){
        for(int j=-1;j<2;j++){
            if(this->world->GetOrganism(this->GetPositionX()+i,this->GetPositionY()+j)== nullptr){
                Position* newPosition = new Position(i,j);
                return newPosition;
            };
        }
    }
    return nullptr;
}

void Animal::Collision() {

}

Animal::~Animal() noexcept {

}
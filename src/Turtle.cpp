#include "Turtle.h"
#include <iostream>

Turtle::Turtle(int x, int y, World *world): Animal(2,1,x,y,world) {

}

void Turtle::Draw() {
    printf("T");
}

void Turtle::Action() {
    int randomise=(rand()%4)+1;
    if(randomise==1){
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
        }
        else{
            tmpOrg->Collision(this, x,y,animalPosition);
        }
    }
}

void Turtle::Collision(Organism *tmpOrg, int x, int y, Position position) {
    if(tmpOrg->checkSpecies(this)){

        //kopiulacja
        Position* breedPosition=tmpOrg->Breed(this);
        if(breedPosition!= nullptr){
            newAnimal(breedPosition);
        }
        printf("KOPULACJA\n");
    }
    else{
        //walka
        if(tmpOrg->GetPower()<5){
            std::cout<<"naura frajerze\n";
        }
        else if(tmpOrg->GetPower()>=this->power){
            this->Kill();
            this->GetWorld()->addToKill(this);
            tmpOrg->Move(x,y);
            tmpOrg->GetWorld()->Erase(this->GetPosition());
            tmpOrg->GetWorld()->Erase(position);

        }
        else{
            tmpOrg->GetWorld()->addToKill(tmpOrg);
            tmpOrg->Kill();
            tmpOrg->GetWorld()->Erase(position);
        }

        printf("WALKA\n");
    }
}

bool Turtle::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Turtle*>(organismTmp) != nullptr;
}

void Turtle::newAnimal(Position* positionXY) {
    int x=positionXY->GetX();
    int y=positionXY->GetY();
    Turtle *newAnimal = new Turtle(x,y, this->world);
    this->world->addOrganism(newAnimal);
}

Turtle::~Turtle() noexcept {

}
#include "Animal.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Animal::Animal(int power, int initiative, int x, int y, World *world):Organism(power,initiative,x,y,world) {

}

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
            tmpOrg->Collision(this, x,y,animalPosition);
        }
}

void Animal::Move(int x, int y) {
    this->position.Move(x,y);
}

void Animal::Move(Position *position) {
    this->position=*position;
}

bool Animal::checkSpecies(Organism* organismTmp) {
 return false;
}

void Animal::newAnimal(Position *position) {}

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

void Animal::Collision(Organism* tmpOrg, int x, int y, Position animalPosition ) {
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
        if(tmpOrg->GetPower()>=this->power){
            this->Kill();
            this->GetWorld()->addToKill(this);
            tmpOrg->GetWorld()->Erase(this->GetPosition());
            tmpOrg->Move(x,y);
           // tmpOrg->GetWorld()->Erase(this->GetPosition());

        }
        else{
            tmpOrg->GetWorld()->addToKill(tmpOrg);
            tmpOrg->Kill();
        }
        tmpOrg->GetWorld()->Erase(animalPosition);
        printf("WALKA\n");
    }
}

Animal::~Animal() noexcept {

}
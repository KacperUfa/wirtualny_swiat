#include "Human.h"
#include <iostream>

Human::Human(int x, int y, World *world): Animal(5,4,x,y,world) {

}

void Human::Draw() {
    printf("O");
}

void Human::Action() {
        if(this->canActivate==false){
            this->countSpecial--;
            if(this->countSpecial==0){
                this->canActivate=true;
            }
            else if (this->countSpecial>4){
                this->power--;
            }

        }
        int x=0;
        int y=0;
        int actualX=this->position.GetX();
        int actualY=this->position.GetY();
        Position animalPosition = this->position;
        Position worldMap=this->world->GetMapSize();
        char cmd;
        bool haveNotChosen=true;

        while (haveNotChosen){

            std::cout<<"       w\n";
            std::cout<<"       ^\n";
            std::cout<<"       |\n";
            std::cout<<"a<-----+----->d\n";
            std::cout<<"       |\n";
            std::cout<<"       |\n";
            std::cout<<"       s\n\n";
            std::cout<<" -------------\n";
            std::cout<<"|   ability   |\n";
            std::cout<<"|      Q      |\n";
            std::cout<<" -------------\n";
            std::cin>>cmd;

            switch (cmd) {
                case 'a':
                    x=-1;
                    haveNotChosen=false;
                    break;
                case 'w':
                    y=-1;
                    haveNotChosen=false;
                    break;
                case 's':
                    y=1;
                    haveNotChosen=false;
                    break;
                case 'd':
                    x=1;
                    haveNotChosen=false;
                    break;
                case 'q':
                    if(canActivate){
                        this->power+=5;
                        this->countSpecial=10;
                        this->canActivate=false;

                        haveNotChosen=false;
                    }
                    else{
                        std::cout<<"It is not ready\n";
                    }
                    break;
                default:
                    break;
            }
        }


    if(actualX==0 && x<0){
        x=0;
    }
    else if(actualX== worldMap.GetX()-1 && x>0){
        x=0;
    }
    if(actualY==0 && y<0){
        y=0;
    }
    else if(actualY== worldMap.GetY()-1 && y>0){
        y=-0;
    }
    if(!(x==0 && y==0)){
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

void Human::Collision(Organism *tmpOrg, int x, int y, Position position) {
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

bool Human::checkSpecies(Organism *organismTmp) {
    return dynamic_cast<Human*>(organismTmp) != nullptr;
}

void Human::newAnimal(Position* positionXY) {
    int x=positionXY->GetX();
    int y=positionXY->GetY();
    Human *newAnimal = new Human(x,y, this->world);
    this->world->addOrganism(newAnimal);
}

Human::~Human() noexcept {

}
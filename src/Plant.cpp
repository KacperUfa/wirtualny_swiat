#include "Plant.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Plant::Plant(int power, int x, int y, World *world): Organism(power,0, x,y,world) {

}

void Plant::Action() {
    srand(time(NULL));
    int spread=(rand()%10)-0;
    if(spread==1){
        int x, y;
        int actualX=this->position.GetX();
        int actualY=this->position.GetY();
        Position plantPosition = this->position;
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


    }
}


void Plant::Collision(Organism* org, int x, int y, Position position) {

}

Plant::~Plant() noexcept {

}
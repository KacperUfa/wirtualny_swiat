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
        int x=(rand()%3)-1;
        int y= (rand()%3)-1;
        //Plant(this->power,this->position.GetX()+x,this->position.GetY()+y,this->world);
    }
}


void Plant::Collision() {

}

Plant::~Plant() noexcept {

}
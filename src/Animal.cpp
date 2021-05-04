#include "Animal.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Animal::Animal(int power, int initiative, int x, int y, World *world):Organism(power,initiative,x,y,world) {

}

void Animal::Action() {
    srand(time(NULL));
    int x=(rand()%3)-1;
    int y= (rand()%3)-1;
    if(y==0 && x==0){
        this->position.Move(x,-1);
    }
    else{
        this->position.Move(x,y);
    }
}

void Animal::Draw() {

}

void Animal::Collision() {

}

Animal::~Animal() noexcept {

}
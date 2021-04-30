#include "Zwierze.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

void Zwierze::action() {
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
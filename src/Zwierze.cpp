#include "Zwierze.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

void Zwierze::action() {
    srand(time(NULL));
    int x=(rand()%3)-1;
    if(x==0){
        int y= (rand()%2)+0;
        if(y==0 && x==0){
            this->position.Move(x,-1);
        }
        else{
            this->position.Move(x,y);
        }
    }

}
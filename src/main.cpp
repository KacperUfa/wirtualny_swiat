#include <iostream>
#include "Organism.h"
#include <vector>
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Position.h"
#include "Wolf.h"

int main(){

    int x, y;
    x=10;
    y=10;
    /*
    std::cout<<"X dimension: "<<std::endl;
    std::cin>>x;
    std::cout<<"\nY dimension: "<<std::endl;
    std::cin>>y;
    std::cout<<"\n";
    if(x>0 && y>0){
        Position worldDimensions = Position(x,y);
    }
    else{
        std::cout<<"It is not funny, bye\n";
        return 0;
    }
     */

    std::vector <Organism*> organisms;
    Wolf *wolf1 = new Wolf(5,5, nullptr);
    organisms.push_back(wolf1);
    World *world1 = new World(x,y, organisms);
    world1->DrawWorld();
    world1->MakeTurn();
    return 0;
}


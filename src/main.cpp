#include <iostream>
#include <ctime>
#include "Organism.h"
#include <vector>
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Position.h"
#include "Wolf.h"
#include "Sheep.h"

int main(){
    srand(time(NULL));
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
    Wolf *wolf1 = new Wolf(4,5, nullptr);
    Wolf *wolf2 = new Wolf(5,5, nullptr);
    Wolf *wolf3 = new Wolf(4,4, nullptr);
    Wolf *wolf4 = new Wolf(5,4, nullptr);
    //Sheep *sheep1 = new Sheep(2,2, nullptr);
    organisms.push_back(wolf1);
    organisms.push_back(wolf2);
    organisms.push_back(wolf3);
    organisms.push_back(wolf4);
    //organisms.push_back(sheep1);
    World *world1 = new World(x,y, organisms);
    world1->DrawWorld();
    while (true){
        int x;
        std::cin>>x;
        if(x==1) break;
        world1->MakeTurn();
        world1->addOrganisms();
        //world1->PlaceOrganisms();
        //world1->remOrganisms();

    }
    return 0;
}


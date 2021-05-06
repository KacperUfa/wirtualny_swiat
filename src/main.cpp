#include <iostream>
#include <ctime>
#include "Organism.h"
#include <vector>
#include "Grass.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Position.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "HeraclemSosnowskyi.h"

int main(){
    srand(time(NULL));
    int x, y;
    x=3;
    y=3;
    /*
    std::cout<<"X dimension: "<<std::endl;
    std::cin>>x;
    std::cout<<"\nY dimension: "<<std::endl;
    std::cin>>y;
    std::cout<<"\n";
    if(x>0 && y>0){
        Position worldDimensions = new Position(x,y);
    }
    else{
        std::cout<<"It is not funny, bye\n";
        return 0;
    }
     */

    std::vector <Organism*> organisms;

    HeraclemSosnowskyi* heraclemSosnowskyi1 = new HeraclemSosnowskyi(1,1,nullptr);
    organisms.push_back(heraclemSosnowskyi1);
    /*
    Fox *fox1 = new Fox(2,3, nullptr);
    Fox *fox2 = new Fox(3,2, nullptr);
    Fox *fox3 = new Fox(7,3, nullptr);
    Fox *fox4 = new Fox(3,7, nullptr);
     */
    Wolf *wolf1 = new Wolf(1,1, nullptr);
    /*
    Wolf *wolf2 = new Wolf(6,5, nullptr);
    Wolf *wolf3 = new Wolf(4,3, nullptr);
    Wolf *wolf4 = new Wolf(7,7, nullptr);
     */
    Sheep *sheep1 = new Sheep(2,2, nullptr);
    Sheep *sheep2 = new Sheep(1,2, nullptr);
    Sheep *sheep3 = new Sheep(1,0, nullptr);
    Sheep *sheep4 = new Sheep(2,1, nullptr);
    /*
    organisms.push_back(fox1);
    organisms.push_back(fox2);
    organisms.push_back(fox3);
    organisms.push_back(fox4);
     */
    //organisms.push_back(wolf1);
    /*
    organisms.push_back(wolf2);
    organisms.push_back(wolf3);
    organisms.push_back(wolf4);
     */
    organisms.push_back(sheep1);
    organisms.push_back(sheep2);
    organisms.push_back(sheep3);
    organisms.push_back(sheep4);
    /*

    Grass *grass1 = new Grass(1,1, nullptr);
    organisms.push_back(grass1);

    */

    Guarana *guarana1 = new Guarana(1,1,nullptr);
    //organisms.push_back(guarana1);

    Dandelion *dandelion1 = new Dandelion(1,1, nullptr);
    //organisms.push_back(dandelion1);

    Nightshade *nightshade1 = new Nightshade(1,1,nullptr);
    //organisms.push_back(nightshade1);
    //organisms.push_back(heraclemSosnowskyi1);
    World *world1 = new World(x,y, organisms);
    world1->DrawWorld();

    while (true){
        int x;
        std::cin>>x;
        if(x==1) break;
        world1->MakeTurn();
        world1->addOrganisms();
        world1->removeOrganisms();
    }

    if(dynamic_cast<Plant*>(sheep1)){
        std::cout<<"essa";
    }
    return 0;
}


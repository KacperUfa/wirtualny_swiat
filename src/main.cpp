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
#include "Turtle.h"
#include "Antelope.h"
#include "Human.h"

void addAnimals(int x, int y, int animalAmount, std::vector <Organism*> *organisms, std::vector<std::vector <Organism*>> *mapTMP){
    for(int i=0;i<animalAmount;i++){
        int tempX, tempY;
        int randAnimal = (rand()%5)+0;
        bool accepted=false;
        do{
            tempX = (rand()%x)+0;
            tempY = (rand()%y)+0;
            if((*mapTMP)[tempY][tempX]== nullptr){
                accepted=true;
            }
        }while(!accepted);

        switch (randAnimal) {
            case 0: {
                Antelope *newAntelope = new Antelope(tempX, tempY, nullptr);
                organisms->push_back(newAntelope);
                (*mapTMP)[tempY][tempX]=newAntelope;
                break;
            }
            case 1:
            {
                Fox *newFox = new Fox(tempX, tempY, nullptr);
                organisms->push_back(newFox);
                (*mapTMP)[tempY][tempX]=newFox;
                break;
            }
            case 2:
            {
                Sheep *newSheep = new Sheep(tempX, tempY, nullptr);
                organisms->push_back(newSheep);
                (*mapTMP)[tempY][tempX]=newSheep;
                break;
            }
            case 3:
            {
                Wolf *newWolf = new Wolf(tempX, tempY, nullptr);
                organisms->push_back(newWolf);
                (*mapTMP)[tempY][tempX]=newWolf;
                break;
            }
            case 4:
            {
                Turtle *newTurtle = new Turtle(tempX, tempY, nullptr);
                organisms->push_back(newTurtle);
                (*mapTMP)[tempY][tempX]=newTurtle;
                break;
            }
            default:
                break;
        }
    }
}

void addPlants(int x, int y, int plantAmount, std::vector <Organism*> *organisms, std::vector<std::vector <Organism*>> *mapTMP){
    for(int i=0;i<plantAmount;i++){
        int tempX, tempY;
        int randPlant = (rand()%5)+0;
        bool accepted=false;
        do{
            tempX = (rand()%x)+0;
            tempY = (rand()%y)+0;
            if((*mapTMP)[tempY][tempX]== nullptr){
                accepted=true;
            }
        }while(!accepted);

        switch (randPlant) {
            case 0: {
                Grass *newGrass = new Grass(tempX, tempY, nullptr);
                organisms->push_back(newGrass);
                (*mapTMP)[tempY][tempX]=newGrass;
                break;
            }
            case 1:
            {
                Dandelion *newDandelion = new Dandelion(tempX, tempY, nullptr);
                organisms->push_back(newDandelion);
                (*mapTMP)[tempY][tempX]=newDandelion;
                break;
            }
            case 2:
            {
                Guarana *newGuarana = new Guarana(tempX, tempY, nullptr);
                organisms->push_back(newGuarana);
                (*mapTMP)[tempY][tempX]=newGuarana;
                break;
            }
            case 3:
            {
                HeraclemSosnowskyi *newHereclemSosnowskyi = new HeraclemSosnowskyi(tempX, tempY, nullptr);
                organisms->push_back(newHereclemSosnowskyi);
                (*mapTMP)[tempY][tempX]=newHereclemSosnowskyi;
                break;
            }
            case 4:
            {
                Nightshade *newNightShade = new Nightshade(tempX, tempY, nullptr);
                organisms->push_back(newNightShade);
                (*mapTMP)[tempY][tempX]=newNightShade;
                break;
            }
            default:
                break;
        }
    }
}

std::vector <Organism*> generateOrganisms(int x, int y){
    int maxAmount = x*y;
    int plantAmount = maxAmount/5;
    //plantAmount=0;
    int animalAmount = maxAmount/4;
    std::vector <Organism*> organisms;
    std::vector<std::vector <Organism*>> mapTMP(y,std::vector<Organism*>(x, nullptr));
    addAnimals(x,y,animalAmount,&organisms,&mapTMP);
    addPlants(x,y,plantAmount,&organisms,&mapTMP);
    int tempX, tempY;
    bool accepted=false;
    do{
        tempX = (rand()%x)+0;
        tempY = (rand()%y)+0;
        if(mapTMP[tempY][tempX]== nullptr){
            accepted=true;
        }
    }while(!accepted);

    Human* newHuman = new Human(tempX,tempY, nullptr);
    organisms.push_back(newHuman);
    mapTMP[tempY][tempX]=newHuman;

    return organisms;
}

int main(){
    srand(time(NULL));
    int x, y;

    /*
    std::cout<<"X dimension: "<<std::endl;
    std::cin>>x;
    std::cout<<"\nY dimension: "<<std::endl;
    std::cin>>y;
    std::cout<<"\n";
    if(x>0 && y>0){
        Position* worldDimensions = new Position(x,y);
    }
    else{
        std::cout<<"It is not funny, bye\n";
        return 0;
    }
    */
    x=15;
    y=5;


    std::vector <Organism*> organisms;

    std::vector <Organism*> organismsFunction=generateOrganisms(x,y);
    /*
    HeraclemSosnowskyi* heraclemSosnowskyi1 = new HeraclemSosnowskyi(1,1,nullptr);
    Fox *fox1 = new Fox(2,3, nullptr);
    Fox *fox2 = new Fox(3,2, nullptr);
    Fox *fox3 = new Fox(7,3, nullptr);
    Fox *fox4 = new Fox(3,7, nullptr);
    Wolf *wolf1 = new Wolf(2,2, nullptr);
    Wolf *wolf2 = new Wolf(6,5, nullptr);
    Wolf *wolf3 = new Wolf(4,3, nullptr);
    Wolf *wolf4 = new Wolf(7,7, nullptr);
    Sheep *sheep1 = new Sheep(2,2, nullptr);
    Sheep *sheep2 = new Sheep(1,2, nullptr);
    Sheep *sheep3 = new Sheep(1,0, nullptr);
    Sheep *sheep4 = new Sheep(2,1, nullptr);
    Turtle *turtle1 = new Turtle(1,1, nullptr);
    Antelope *antelope1 = new Antelope(0,0, nullptr);
    Human* human1 = new Human(1,1, nullptr);
    */
    /*
    organisms.push_back(heraclemSosnowskyi1);
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

    //organisms.push_back(sheep1);
    //organisms.push_back(sheep2);
    //organisms.push_back(sheep3);
    //organisms.push_back(sheep4);
    //organisms.push_back(turtle1);
    //organisms.push_back(antelope1);
    //organisms.push_back(human1);

    Grass *grass1 = new Grass(2,2, nullptr);
    organisms.push_back(grass1);

    Guarana *guarana1 = new Guarana(1,1,nullptr);
    //organisms.push_back(guarana1);

    Dandelion *dandelion1 = new Dandelion(1,1, nullptr);
    //organisms.push_back(dandelion1);

    Nightshade *nightshade1 = new Nightshade(1,1,nullptr);
    //organisms.push_back(nightshade1);
    //organisms.push_back(heraclemSosnowskyi1);
     */

    World *world1 = new World(x,y, organismsFunction);
    world1->DrawWorld();
    world1->SortOrganisms();
    while (true){
        std::cout<<"Wirtual world, projected by Kacper Ufa 184501\n";
        int x;
        std::cout<<"1. Next Move\n";
        std::cout<<"2. Quit\n";
        std::cin>>x;
        if(x==1){
            world1->MakeTurn();
            world1->addOrganisms();
            world1->removeOrganisms();
            world1->SortOrganisms();
        }
        else if(x==2) break;
    }
    return 0;
}


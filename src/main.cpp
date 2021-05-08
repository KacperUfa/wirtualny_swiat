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
#include "SavoLoader.h"

/*
Main file in which everything is initialised and the world is generated based on the dimensions that player gave
 */


//function for adding random animals and placing them on random positions on the map
void addAnimals(int x, int y, int animalAmount, std::vector<Organism *> *organisms,
                std::vector<std::vector<Organism *>> *mapTMP) {
    for (int i = 0; i < animalAmount; i++) {
        int tempX, tempY;
        int randAnimal = (rand() % 5) + 0;
        bool accepted = false;
        do {
            tempX = (rand() % x) + 0;
            tempY = (rand() % y) + 0;
            if ((*mapTMP)[tempY][tempX] == nullptr) {
                accepted = true;
            }
        } while (!accepted);

        switch (randAnimal) {
            case 0: {
                Antelope *newAntelope = new Antelope(tempX, tempY, nullptr);
                organisms->push_back(newAntelope);
                (*mapTMP)[tempY][tempX] = newAntelope;
                break;
            }
            case 1: {
                Fox *newFox = new Fox(tempX, tempY, nullptr);
                organisms->push_back(newFox);
                (*mapTMP)[tempY][tempX] = newFox;
                break;
            }
            case 2: {
                Sheep *newSheep = new Sheep(tempX, tempY, nullptr);
                organisms->push_back(newSheep);
                (*mapTMP)[tempY][tempX] = newSheep;
                break;
            }
            case 3: {
                Wolf *newWolf = new Wolf(tempX, tempY, nullptr);
                organisms->push_back(newWolf);
                (*mapTMP)[tempY][tempX] = newWolf;
                break;
            }
            case 4: {
                Turtle *newTurtle = new Turtle(tempX, tempY, nullptr);
                organisms->push_back(newTurtle);
                (*mapTMP)[tempY][tempX] = newTurtle;
                break;
            }
            default:
                break;
        }
    }
}

//function for adding random plants and placing them on random positions on the map
void addPlants(int x, int y, int plantAmount, std::vector<Organism *> *organisms,
               std::vector<std::vector<Organism *>> *mapTMP) {
    for (int i = 0; i < plantAmount; i++) {
        int tempX, tempY;
        int randPlant = (rand() % 5) + 0;
        bool accepted = false;
        do {
            tempX = (rand() % x) + 0;
            tempY = (rand() % y) + 0;
            if ((*mapTMP)[tempY][tempX] == nullptr) {
                accepted = true;
            }
        } while (!accepted);

        switch (randPlant) {
            case 0: {
                Grass *newGrass = new Grass(tempX, tempY, nullptr);
                organisms->push_back(newGrass);
                (*mapTMP)[tempY][tempX] = newGrass;
                break;
            }
            case 1: {
                Dandelion *newDandelion = new Dandelion(tempX, tempY, nullptr);
                organisms->push_back(newDandelion);
                (*mapTMP)[tempY][tempX] = newDandelion;
                break;
            }
            case 2: {
                Guarana *newGuarana = new Guarana(tempX, tempY, nullptr);
                organisms->push_back(newGuarana);
                (*mapTMP)[tempY][tempX] = newGuarana;
                break;
            }
            case 3: {
                HeraclemSosnowskyi *newHereclemSosnowskyi = new HeraclemSosnowskyi(tempX, tempY, nullptr);
                organisms->push_back(newHereclemSosnowskyi);
                (*mapTMP)[tempY][tempX] = newHereclemSosnowskyi;
                break;
            }
            case 4: {
                Nightshade *newNightShade = new Nightshade(tempX, tempY, nullptr);
                organisms->push_back(newNightShade);
                (*mapTMP)[tempY][tempX] = newNightShade;
                break;
            }
            default:
                break;
        }
    }
}

/*
function for estimating the amount of plants and animals, then it calls addPlants() and addAnimals() functions,
and additionally it creates human and place him on the random free field
 */
std::vector<Organism *> generateOrganisms(int x, int y) {
    int maxAmount = x * y;
    int plantAmount = maxAmount / 5;
    int animalAmount = maxAmount / 4;
    std::vector<Organism *> organisms;
    std::vector<std::vector<Organism *>> mapTMP(y, std::vector<Organism *>(x, nullptr));
    addAnimals(x, y, animalAmount, &organisms, &mapTMP);
    addPlants(x, y, plantAmount, &organisms, &mapTMP);
    int tempX, tempY;
    bool accepted = false;
    do {
        tempX = (rand() % x) + 0;
        tempY = (rand() % y) + 0;
        if (mapTMP[tempY][tempX] == nullptr) {
            accepted = true;
        }
    } while (!accepted);

    Human *newHuman = new Human(tempX, tempY, nullptr);
    organisms.push_back(newHuman);
    mapTMP[tempY][tempX] = newHuman;

    return organisms;
}

int main() {
    srand(time(NULL));
    int n;
    SavoLoader* save = new SavoLoader();
    World *world1;
    std::cout << "Hello! " << std::endl;
    std::cout << "1. Make new world" << std::endl;
    std::cout << "2. Load last saved world " << std::endl;
    std::cin>>n;
    if(n==1){
        int x, y;
        std::cout << "X dimension: " << std::endl;
        std::cin >> x;
        std::cout << "\nY dimension: " << std::endl;
        std::cin >> y;
        std::cout << "\n";
        if (x > 0 && y > 0) {
            Position *worldDimensions = new Position(x, y);
        } else {
            std::cout << "It is not funny, bye\n";
            return 0;
        }
        system("cls");
        std::vector<Organism *> organismsFunction = generateOrganisms(x, y);
        world1 = new World(x, y, organismsFunction);
    }
    else if(n==2){
        world1 = save->loadWorld();
    }
    else{
        return 0;
    }

    world1->DrawWorld();
    world1->SortOrganisms();

    while (true) {
        //system("cls");
        std::cout << "Virtual world, designed by Kacper Ufa 184501\n";
        char x;
        std::cout << "1. Next Move\n";
        std::cout << "2. Save game\n";
        std::cout << "3. Quit\n";
        std::cin >> x;
        if (x == '1') {
            system("cls");
            world1->MakeTurn();
            world1->addOrganisms();
            world1->removeOrganisms();
            world1->SortOrganisms();
        } else if (x == '2') {
            save->saveWorld(world1);
            break;
        } else if (x == '3') break;
        else{
            std::cout<<"Something went wrong, try again\n";
        }
    }
    return 0;
}


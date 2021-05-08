#include "SavoLoader.h"
#include "Grass.h"
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
#include <typeinfo>
#include <fstream>

SavoLoader::SavoLoader() {
}

FILE *SavoLoader::getFilepointer() const {
    return filepointer;
}

void SavoLoader::setFilepointer(FILE *filepointer) {
    SavoLoader::filepointer = filepointer;
}

bool SavoLoader::saveWorld(World *world) {
    std::ofstream file;
    this->filepointer = fopen("../savegame.txt", "wb+");
    fclose(filepointer);
    file.open("../savegame.txt");
    char x = world->GetMapSize().GetX();
    int y = world->GetMapSize().GetY();
    std::vector<Organism *> organisms = world->getOrganisms();
    file << (char) x + 0 << " " << (char) y + 0 << std::endl;
    for (auto iter = organisms.begin(); iter != organisms.end(); iter++) {
        if(dynamic_cast<Human*>((*iter))){
            Human* humanTmp = dynamic_cast<Human*>((*iter));
            file << (*iter)->GetName() << " " << (*iter)->GetPositionX() + 0 << " " << (*iter)->GetPositionY() + 0 << " "
                 << (*iter)->GetPower() + 0 <<  " " << humanTmp->GetActivate() <<" " <<
                 humanTmp->GetSpecial() + 0 <<std::endl;
        }
        else{
            file << (*iter)->GetName() << " " << (*iter)->GetPositionX() + 0 << " " << (*iter)->GetPositionY() + 0 << " "
                 << (*iter)->GetPower() + 0 << std::endl;
        }

    }
    file.close();
    return true;
}

World *SavoLoader::loadWorld() {
    std::vector<Organism *> organisms;
    std::ifstream file;
    file.open("../savegame.txt");
    if (file.is_open()) {
        int x, y, xTmp, yTmp, powerTmp;
        std::string className;
        file >> x;
        file >> y;
        std::vector<std::vector<Organism *>> mapTMP(y, std::vector<Organism *>(x, nullptr));
        Organism *organism;
        while (true) {
            file >> className;
            file >> xTmp;
            file >> yTmp;
            file >> powerTmp;
            //powerTmp = 5;

            if (className == "Antelope") {
                organism = new Antelope(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Dandelion") {
                organism = new Dandelion(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Fox") {
                organism = new Fox(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Grass") {
                organism = new Grass(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Guarana") {
                organism = new Guarana(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "HeraclemSosnowskyi") {
                organism = new HeraclemSosnowskyi(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Human") {
                std::string active;
                int counter;
                file >> active;
                file >> counter;
                Human* newHuman = new Human(xTmp, yTmp, nullptr);
                if(active == "true"){
                    newHuman->SetActivate(true);
                }
                else{
                    newHuman->SetActivate(false);
                }
                newHuman->SetSpecial(counter);
                newHuman->SetPower(powerTmp);
                organisms.push_back(newHuman);
            } else if (className == "Nightshade") {
                organism = new Nightshade(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Sheep") {
                organism = new Sheep(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Turtle") {
                organism = new Turtle(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            } else if (className == "Wolf") {
                organism = new Wolf(xTmp, yTmp, nullptr);
                organism->SetPower(powerTmp);
            }
            if(className != "Human"){
                organisms.push_back(organism);
            }


            if (file.eof()) break;
        }
        World *newWorld = new World(y, x, organisms);
        file.close();
        return newWorld;
    } else {
        std::cout << "file read error\n";
    }
    return nullptr;
}

SavoLoader::~SavoLoader() {

}

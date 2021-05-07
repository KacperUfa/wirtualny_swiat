//
// Created by matih on 07.05.2021.
//

#include "SavoLoader.h"
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
    file << (char)x+0 << " " << (char)y+0 << std::endl;
    file << (char)x+0 << " " << (char)y+0 << std::endl;
    for (auto iter = organisms.begin(); iter != organisms.end(); iter++) {
       file << typeid(*iter).name() << " " << (*iter)->GetPositionX() + 0 << " " << (*iter)->GetPositionY() + 0 << std::endl;
    }
    file.close();
    return true;
}

bool SavoLoader::loadWorld() {
    return false;
}

SavoLoader::~SavoLoader() {

}

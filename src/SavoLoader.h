#ifndef WIRTUALNY_SWIAT_SAVOLOADER_H
#define WIRTUALNY_SWIAT_SAVOLOADER_H

#include <cstdio>
#include "World.h"

class SavoLoader {

    FILE *filepointer;

public:
    SavoLoader();

    FILE *getFilepointer() const;

    void setFilepointer(FILE *filepointer);

    bool saveWorld(World* world);

    World* loadWorld();

    virtual ~SavoLoader();

};


#endif //WIRTUALNY_SWIAT_SAVOLOADER_H

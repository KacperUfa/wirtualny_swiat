
#ifndef WIRTUALNY_SWIAT_ZWIERZE_H
#define WIRTUALNY_SWIAT_ZWIgit ERZE_H
#include "Organizm.h"

class Zwierze : public Organizm {
private:
public:
    void draw () override;
    void collision () override;
    void action () override;

    ~Zwierze() override;
};


#endif //WIRTUALNY_SWIAT_ZWIERZE_H

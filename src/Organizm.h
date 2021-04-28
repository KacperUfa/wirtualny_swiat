#ifndef WIRTUALNY_SWIAT_ORGANIZM_H
#define WIRTUALNY_SWIAT_ORGANIZM_H


class Organizm {
private:
    int power;
    int initiative;
    class position{
        int x;
        int y;
    };
    int world;
public:
    Organizm(int power, int initiative, int x, int y, int world);
    virtual void action();
    virtual void collision();
    virtual void draw();
};


#endif //WIRTUALNY_SWIAT_ORGANIZM_H

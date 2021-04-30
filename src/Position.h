//
// Created by kacpe on 29.04.2021.
//

#ifndef WIRTUALNY_SWIAT_POSITION_H
#define WIRTUALNY_SWIAT_POSITION_H


class Position {
    int x;
    int y;
public:
    void SetX(int x);
    void SetY(int y);
    int GetX();
    int GetY();
    void Move(int x, int y);
};


#endif //WIRTUALNY_SWIAT_POSITION_H

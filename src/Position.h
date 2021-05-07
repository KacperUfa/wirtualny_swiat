//
// Created by kacpe on 29.04.2021.
//

#ifndef WIRTUALNY_SWIAT_POSITION_H
#define WIRTUALNY_SWIAT_POSITION_H

/*
Base class used for position and dimensions
 */

class Position {
    int x;
    int y;
public:
    Position(int x, int y);

    void SetX(int x);

    void SetY(int y);

    int GetX();

    int GetY();

    Position *GetPosition();

    void Move(int x, int y);

    void Erase();

    ~Position();
};


#endif //WIRTUALNY_SWIAT_POSITION_H

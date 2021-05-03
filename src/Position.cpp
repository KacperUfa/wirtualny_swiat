#include "Position.h"
#include <iostream>
Position::Position(int x, int y) : x(x), y(y){
    std::cout<<"position X:"<<this->x<<" Y: "<<this->y<<std::endl;
}

void Position::SetX(int x){
    this->x=x;
}
void Position::SetY(int y){
    this->y=y;
}
int Position::GetX(){
    return this->x;
}
int Position::GetY(){
    return this->y;
}
void Position::Move(int x, int y){
    this->x+=x;
    this->y+=y;
}

Position::~Position() {

}
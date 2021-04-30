#include "Position.h"

Position::Position(int x, int y) {
    this->x=x;
    this->y=y;
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
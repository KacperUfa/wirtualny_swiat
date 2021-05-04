//
// Created by kacpe on 04.05.2021.
//

#include "Wolf.h"

Wolf::Wolf(int x, int y, World *world): Animal(9,5,x,y,world) {

}

void Wolf::Draw() {
    printf("W");
}

Wolf::~Wolf() noexcept {

}
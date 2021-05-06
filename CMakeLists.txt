cmake_minimum_required(VERSION 3.17)
project(wirtualny_swiat)

set(CMAKE_CXX_STANDARD 14)

add_executable(wirtualny_swiat src/main.cpp
        src/World.h src/World.cpp
        src/Position.h src/Position.cpp
        src/Organism.h src/Organism.cpp
        src/Animal.h src/Animal.cpp
        src/Plant.h src/Plant.cpp
        src/Wolf.h src/Wolf.cpp
        src/Sheep.h src/Sheep.cpp
        src/Fox.h src/Fox.cpp
        src/Grass.h src/Grass.cpp
        src/Dandelion.h src/Dandelion.cpp
        src/Guarana.h src/Guarana.cpp
        src/Nightshade.h src/Nightshade.cpp
        src/HeraclemSosnowskyi.h src/HeraclemSosnowskyi.cpp)
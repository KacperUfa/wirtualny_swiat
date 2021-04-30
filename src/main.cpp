#include <iostream>
#include "Organizm.h"
#include "Zwierze.h"
#include "Position.h"

int main(){
    int x, y;
    std::cout<<"X dimension: "<<std::endl;
    std::cin>>x;
    std::cout<<"\nY dimension: "<<std::endl;
    std::cin>>y;
    std::cout<<"\n";
    if(x>0 && y>0){
        Position worldDimensions = Position(x,y);
    }
    else{
        std::cout<<"It is not funny, bye\n";
        return 0;
    }

    return 0;
}


#include <iostream>
#include "cube.h"

int main(){
    double length = 5;
    mine::Cube c(2), c3; // default with argument, default
    std::cout<<c.getVolume()<<std::endl;
    c.setLength(length);

    mine::Cube c2 = c; // copy
    c3 = c; //  no copy
    std::cout<<c.getVolume()<<std::endl;
    return 0;
}
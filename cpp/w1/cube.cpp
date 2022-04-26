#include "cube.h"
#include <iostream>

using namespace std;

namespace mine {

Cube::Cube(){
    length_=1;
    std::cout<<"default"<<std::endl;
}

Cube::Cube(double defaultLength){
    length_ = defaultLength;
    std::cout<<"default with argument"<<std::endl;
}

Cube::Cube(const Cube &obj){
    length_ = obj.length_;
    std::cout<<"copy"<<std::endl;
}

Cube & Cube::Cube::operator=(const Cube &obj){
    length_ = obj.length_;
    std::cout<<"copy assignment"<<std::endl;
    return *this;
}

double Cube::getVolume(){
    return length_*length_*length_;
}

double Cube::getSurfaceArea(){
    return 6*length_*length_;
}

void Cube::setLength(double length){
    length_ = length;
}

}
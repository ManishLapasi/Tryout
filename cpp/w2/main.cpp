#include <iostream>
using namespace std;


int main(){

    int i = 2, j = 4,  k = 8;
    int *p = &i, *q = &j, *r = &k;

    k = i;
    std::cout<<i<<j<<k<<*p<<*q<<*r<<std::endl;
    // 2 4 2 2 4 2
    p = q;
    std::cout<<i<<j<<k<<*p<<*q<<*r<<std::endl;
    // 2 4 2 4 4 2
    *q = *r;
    std::cout<<i<<j<<k<<*p<<*q<<*r<<std::endl;
    // 2 2 2 2 2 2

    int *x = new int;   //initialise int space in heap
    int &y = *x;       // alias pointing to value in heap
    y = 4;      // change heap value

    std::cout<<&x<<std::endl;  // stack big address
    std::cout<<x<<std::endl;   // heap small address
    std::cout<<*x<<std::endl;    // 4, coz changed

    std::cout<<&y<<std::endl;    // heap small address
    std::cout<<y<<std::endl;     // 4
    //std::cout<<*y<<std::endl;

    int *z = new int(2);

    std::cout<<z<<std::endl;    // heap small address
    std::cout<<*z<<std::endl;   // 2
    std::cout<<&z<<std::endl;   // stack big address

    delete z;
    delete x;
    
    z = nullptr;
    x = nullptr;
    
    return 0;


}
#include "iostream"

using namespace std;

int main(){

    int *i = new int;
    *i = 0;
    int &j = *i;
    std::cout<<i<<"\n"<<j<<"\n"<<*i<<"\n";
    j++;
    std::cout<<i<<"\n"<<j<<"\n"<<*i<<"\n";
    return 0;
}
#include "iostream"

using namespace std;

class Cube{
    private:
        double length;
    public:
        Cube() {length = 1;}
        Cube(double l) {length = l;}
        double Volume(){return length*length*length;}
        Cube(const Cube &obj){length = obj.length;}
        Cube operator=(const Cube &obj){
            Cube temp;
            temp.length = obj.length; 
            return temp;
        }
        ~Cube(){length = 0;}
};

int main(){

    Cube c(5);
    std::cout<<c.Volume()<<endl;
    c.~Cube();
    std::cout<<c.Volume()<<endl;
    
    return 0;
}
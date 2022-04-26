#include "iostream"
#include "sstream"

using namespace std;

class Polygon{
    protected:
        int width, height;
    public:
        Polygon(int w, int h) : width(w), height(h) {};
        virtual float area() {return 0;}
};

class Output{
    public:
        static void print(int i);
};

void Output::print(int i){
    std::cout<<i;
}

class Triangle: public Polygon, public Output {
    public:
        Triangle(int a, int b) : Polygon(a,b) {};
        float area() {return 0.5*width*height;}; 
};

class Rectangle: public Polygon, public Output {
    public:
        Rectangle(int w, int h): Polygon(w,h) {};
        float area() {return width*height;};
};

int main(){

    Triangle t1(1,2);
    Rectangle r1(3,4);

    std::cout<<t1.area()<<"\t"<<r1.area()<<"\n";
    t1.print(t1.area());
    std::cout<<"\t";
    r1.print(r1.area());

    return 0;
}
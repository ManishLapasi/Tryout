#include "iostream"
#include "sstream"

using namespace std;

const float pi = 3.14;

class circle{
    private:
        float radius;
    public:
        void setRadius(float r);
        float area(){return pi*radius*radius;};
        float perimeter(){return 2*pi*radius;};
};

void circle::setRadius(float r){
    radius = r;
}

class square{
    private:
        float side;
    public:
        square(float);
        float area(){return side*side;}
        float perimeter(){return 4*side;}
};

square::square(float a){
    side = a;
}

class rectangle{
    private:
        float width, length;
    public:
        rectangle();
        rectangle(float w, float l): width(w),length(l){};
        float area(){return width*length;}
        float perimeter(){return 2*(width+length);}
};

rectangle::rectangle(){
    width = 1, length = 1;
}

class strptr{
    public:
        string * str;
        strptr() {};
        strptr(string inputstr) : str(new string(inputstr)) {};
        strptr(const strptr& obj) : str(new string(*(obj.str))) {};
        ~strptr() {delete str;}
};

void copyconstdemo(){

    string inputstr;
    std::cout<<"Enter string:";
    getline(cin,inputstr);

    strptr s1(inputstr);
    strptr s2 = s1;
    std::cout<<s1.str<<"\t"<<s2.str<<"\n";
    std::cout<<*(s1.str)<<"\t"<<*(s2.str)<<"\n";
    *(s1.str) = "newstr";
    std::cout<<s1.str<<"\t"<<s2.str<<"\n";
    std::cout<<*(s1.str)<<"\t"<<*(s2.str)<<"\n";
    
}

void circledemo(){

    circle c1;
    float r;
    std::cout<<"Enter radius: ";
    cin>>r;
    c1.setRadius(r);
    std::cout<<"area: "<<c1.area()<<"\tperimeter: "<<c1.perimeter();

}

void squaredemo(){
    
    float a;
    std::cout<<"Enter side length:";
    cin>>a;
    square s1(a);
    std::cout<<"area: "<<s1.area()<<"\tperimeter: "<<s1.perimeter();
    
}

void rectdemo(){

    float w,l;
    std::cout<<"Enter length: ";
    std::cin>>l;
    std::cout<<"Enter width: ";
    std::cin>>w;
    rectangle r1;
    rectangle r2(w,l);
    std::cout<<"Default rectangle:\n";
    std::cout<<"area: "<<r1.area()<<"\tperimeter: "<<r1.perimeter();
    std::cout<<"\nUser's rectangle\n";
    std::cout<<"area: "<<r2.area()<<"\tperimeter: "<<r2.perimeter();
    
}

void basicClass(){

    int choice;
    string inputstring;
    std::cout<<"\t1.Circle\n\t"<<"2.Square\n\t"<<"3.Rectangle\n\t";
    getline(cin,inputstring);
    stringstream(inputstring)>>choice;
    switch (choice){
        case 1:
            circledemo();break;
        case 2:
            squaredemo();break;
        case 3:
            rectdemo();break;
        default:
            std::cout<<"Invalid choice\n";break;
    }



    square s1(1);

}

void ptrClass(){

    rectangle r1(1.5,2.1);
    rectangle * r2, * r3, * r4;
    r2 = &r1;
    r3 = new rectangle (2,3);
    r4 = new rectangle[2] {{1,2},{3,4}};

    std::cout<<"rectangle\t"<<"area\t"<<"perimeter\n";
    std::cout<<"r1\t"<<r1.area()<<"\t"<<r1.perimeter()<<"\n";
    std::cout<<"r2\t"<<r2->area()<<"\t"<<r2->perimeter()<<"\n";
    std::cout<<"r3\t"<<r3->area()<<"\t"<<r3->perimeter()<<"\n";

    for( int i: {0,1}){
        std::cout<<"r4\t"<<r4[i].area()<<"\t"<<r4[i].perimeter()<<"\n";
    }

}

int main (){

    int choice;
    string inputstring;

    std::cout<<"Choices:\n\t"<<"1.Classes\n\t"<<"2.Classes and Pointers\n\t"<<"3.Copy constructors";
    getline(cin,inputstring);
    stringstream(inputstring)>>choice;

    switch (choice){
        case 1:
            basicClass();break;
        case 2:
            ptrClass();break;
        case 3:
            copyconstdemo();break;
        default:
            std::cout<<"invalid choice\n";break;
    }

    return 0;
}
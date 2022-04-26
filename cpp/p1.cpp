#include "iostream"
#include "typeinfo"
#include "sstream"

using namespace std;

int dataTypesAndIO(){
    
    std::cout<<"hello there!\n";
        
    float a = 1, b = 2;
    std::cout<<a+b;
    std::cout<<"\n"<<a-b;

    auto res = a*b;
    decltype(res) res2;
    std::cout<<endl<<typeid(res).name()<<endl<<typeid(res2).name()<<endl;

    string s1 = "general kenobi!";
    std::cout<<s1;

    int dec = 0113;
    std::cout<< dec + 2<<endl;

    string inputstring;
    int num;
    std::cout<<"Enter num: ";
    getline(cin,inputstring);
    stringstream(inputstring) >> num;

    std::cout<<num;
    return 0;
}

int loops(){
    
    int i=0;
    for(i;i<5;i++)
    {
        std::cout<<i+1<<endl;
    }
    std::cout<<"end of for\n";

    i=0;
    while(i<5){
        i++;
        cout<<i<<endl;
    };
    std::cout<<"end of while\n";

    do{
        cout<<i++<<endl;
    }while(i<5);
    std::cout<<"end of do while\n";

    std::cout<<i<<endl;

    for(char c : "hello")
    {
        if(c=='h'){continue;}
        std::cout<<c<<endl;
        if(c=='l'){break;}
    }

    for(char c : "hello"){
        switch (c){
            case 'h':
                std::cout<<"H";
                break;
            default:
                std::cout<<c;
        }
    }

    return 0;
}

int byRefFunc(int& a, int& b){
    a *= 2, b*= 3;
    return a+b;
}

void byRefFuncInit(int z = 1){
    int x = 2, y = 3;
    std::cout<<x<<"\t"<<y<<"\t"<<z<<"\n";
    z = byRefFunc(x,y);
    std::cout<<x<<"\t"<<y<<"\t"<<z<<endl; 
    return;
}

template <class T, int N>
T sum(T a, T b){
    T res = a+b+N;
    return res;
}

int scopeFunc(){
    int x = 2, y = 3;
    for(int i=0;i<2;i++){
        int x = 3;
        x = x*3;
        std::cout<<x<<"\t"<<y<<"\n";        
    }
    return 0;
}

namespace n1{
    int val() {return 5;}
}

namespace n2{
    const double pi = 3.14;
    double val() {return 2*pi;}
}

int nsFunc(){
    double pi = 22/7;
    std::cout<<"\t"<<n1::val()<<"\t"<<n2::val()<<"\t"<<pi<<"\t"<<n2::pi<<"\n";
    return 0;
}

void printArr(int arr[][3], int d1, int d2){

    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            std::cout<<arr[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    return;

}

void printArr(int arr[], int d1, int d2){

    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            std::cout<<arr[i*d1+j]<<"\t";
        }
        std::cout<<"\n";
    }
    return;

}

void arrayFunc2(){
    int num1[5][3], num2[5*3];
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            num1[i][j] = (i+1)*(j+1);
            num2[i*5+j] = (i+1)*(j+1);
        }
    }

    printArr(num1,5,3);
    printArr(num2,5,3);
    return;
}

int arrayFunc(){
    int num[5] = {1,2,3,4,5};
    for(int i=0;i<sizeof(num)/sizeof(int);i++){
        num[i] *= num[i];
        std::cout<<num[i]<<"\t";
    }

    arrayFunc2();
    return 0;
}

void charVString(){
    char cstr[] = "Hello There!";
    string str = "General Kenobi!";
    string str2 = cstr;
    for(int i=0;i<sizeof(cstr)/sizeof(char);i++){std::cout<<cstr[i];}
    std::cout<<" "<<str;
    std::cout<<"\n"<<str<<" "<<str2;
}

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return abs(a-b);
}

int operation(int a, int b, int(*func)(int,int)){
    return (*func)(a,b);
}

void dm(){
    std::cout<<"input size of array:";
    string str; int sizeArr;
    getline(cin,str);
    stringstream(str)>>sizeArr;
    int * ptr = new int[sizeArr];
    for(int i=0;i<sizeArr;i++){
        *(ptr+i) = (i+1);
        std::cout<<ptr[i];
    }
    delete ptr;
}

void ptrStuff(){
    int val = 5;
    int* valAd = &val;
    std::cout<<"val "<<val<<" is stored at address "<<valAd;
    valAd += 1;
    std::cout<<"address "<<valAd<<" now contains value "<<*valAd<<"\n";

    int myArr[5] = {1,2,3,4,5};
    int * myArrptr = myArr;
    *myArrptr = 10;
    *myArrptr++; *myArrptr = 20;
    myArrptr = &myArr[2]; *myArrptr = 30;
    myArrptr = myArr + 3; *myArrptr = 40;
    myArrptr = myArr; *(myArr+4) = 50; 

    for(int i=0;i<5;i++){
        std::cout<<myArr[i]<<"\t";
    }

    int* p = myArr;
    std::cout<<endl<<*(p++)<<endl;
    std::cout<<*p<<endl;
    std::cout<<++(*p);

    std::cout<<operation(1,4,subtract);

    delete myArrptr, p, valAd;

    return;
}

void ds(){

    struct movie{
        string name;
        int year;
    };

    struct person{
        string name;
        int age;
        movie favMovie;
    };

    movie Arrival, JoJoRabbit;
    Arrival.name = "Arrival", Arrival.year = 2016;
    JoJoRabbit.name = "Jojo Rabbit", JoJoRabbit.year = 2018;

    person Manish, Shriya;
    Manish.name = "Manish", Manish.age = 24, Manish.favMovie = Arrival;
    Shriya.name = "Shriya", Shriya.age = 22, Shriya.favMovie = JoJoRabbit;

    person pers[2];
    pers[0] = Manish;
    pers[1] = Shriya;

    for(person member:pers){
        std::cout<<member.name<<"\t"<<member.age<<"\t"<<member.favMovie.name<<"\n";
    }

    person * ptr = pers;
    (ptr+1)->favMovie = Arrival;
    ptr[0].favMovie = JoJoRabbit;

    for(person member:pers){
        std::cout<<member.name<<"\t"<<member.age<<"\t"<<member.favMovie.name<<"\n";
    }

}


int main(){

    std::cout<<"Choices:\n\t"<<"1. dataTypesAndIO\n\t"<<"2. loops\n\t"<<"3. refFunc\n\t";
    std::cout<<"4. Overload\n\t"<<"5. Scopes\n\t"<<"6. namespaces\n\t";
    std::cout<<"7. Arrays\n\t"<<"8. Char arrays and strings\n\t"<<"9. Pointers\n\t";
    std::cout<<"10. Dynamic Mem\n\t"<<"11. Data structures\n\t";
    string inputstring;
    int choice;
    getline(cin,inputstring);
    stringstream(inputstring)>>choice;

    switch(choice){
        case 1:
            dataTypesAndIO();break;
        case 2:
            loops();break;
        case 3:
            byRefFuncInit();break;
        case 4:
            std::cout<<sum<int,2>(1.9,2.1)<<"\t"<<sum<float,1>(1.5,2.1);break;
        case 5:
            scopeFunc();break;
        case 6:
            nsFunc();break;
        case 7:
            arrayFunc();break;
        case 8:
            charVString();break;
        case 9:
            ptrStuff();break;
        case 10:
            dm();break;
        case 11:
            ds();break;
        default:
            std::cout<<"invalid choice\n";break;
    }

    return 0;
}
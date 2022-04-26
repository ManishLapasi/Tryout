// overloading operators example
#include <iostream>
using namespace std;

class CVector{
    public:
        int x,y;
        int * xptr = &x;
        CVector() {};
        CVector(int a, int b, string inputstr) : x(a),y(b) {};
        CVector operator - (const CVector&);
        CVector operator = (const CVector&);
        ~CVector() { delete xptr;}
};

CVector CVector::operator- (const CVector& param){
    CVector temp;
    temp.x = x - param.x;
    temp.y = y - param.y;
    return temp;
}

CVector CVector::operator= (const CVector& param){
    x = param.x, y = param.y;
    return *this;
}

CVector operator+ (const CVector& p1, const CVector& p2){
    CVector temp (p1.x+p2.x, p1.y+p2.y);
    return temp;
}

int main(){

    CVector p1 (1,2), p2 (3,4);
    CVector res = p1 + p2;
    std::cout<<res.x<<","<<res.y<<endl;
    res = p1 - p2;
    std::cout<<res.x<<","<<res.y;    
    return 0;

}
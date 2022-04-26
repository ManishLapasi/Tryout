#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

double num_moves(double n, int s1, int s2, int s3){

    if(n==1){return 1;}
    return pow(2,n-1) + num_moves(n-1, s3, s2, s1);

}

int main(){

    int s1 = 1, s2 = 2, s3 = 3;

    double n;
    cout<<"enter num of discs:";
    cin>>n;
    cout<<num_moves(n,s1,s2,s3);

    return 0;
}
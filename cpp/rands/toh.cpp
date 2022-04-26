#include<iostream>

using namespace std;

void toh (int num_plates, int from_rod, int to_rod, int using_rod){
    if(num_plates==1){
        cout<<"move "<<from_rod<<" to "<<to_rod<<endl;
    }
    else{
    toh(num_plates-1,from_rod,using_rod,to_rod);
    toh(1,from_rod,to_rod,using_rod);
    toh(num_plates-1,using_rod,to_rod,from_rod);
    }

}


int main(){
    int N = 5;
    toh(N,1,3,2);
    return 0;
}
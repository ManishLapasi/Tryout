#include "iostream"

using namespace std;

int pos(int * sortedArr, int num, int size){

    int i = 0, j = size;

    if(sortedArr[i] == num){return i;}
    if(sortedArr[j] == num){return j;}

    int index = (i+j)/2;

    while(index != i && index != j){
        if(num == sortedArr[index]){
            return index;
        }
        if(num > sortedArr[index]){
            i = index;
        }
        if(num < sortedArr[index]){
            j = index;
        }
        index = (i+j)/2;
    }

    return -1;

}

int main(){

    int arr[] = {1,2,3,4,5,6,7,7,8};

    int num = 6;
    
    int res = pos(arr, num, sizeof(arr)/sizeof(int)-1);

    if(res==-1){std::cout<<"not found";}
    else{std::cout<<res;}

    
    return 0;
    
}
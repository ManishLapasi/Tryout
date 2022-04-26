#include "iostream"

using namespace std;

void solve(int * arr, int size){

    for(int i=1; i<size;i++){
        int j = i-1;
        int temp = arr[i];
        while (j >= 0 && temp<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

}


int main(){

    int arr[10] = {2,3,4,5,1,7,2,4,5,1};
    int size = sizeof(arr)/sizeof(int);
    solve(arr, size);

    for(int i=0;i<10;i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}
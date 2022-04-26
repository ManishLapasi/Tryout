#include "iostream"

using namespace std;

void solve(int * arr, int size){

    for(int i=0; i<size;i++){
        int j = 0;
        if(arr[j]<=arr[i] && j<i){
            j++;
        }
        if(j==i){
            continue;
        }
        else{
            int tempval = arr[i];
            for(int k = i; k > j; k--){
                arr[k] = arr[k-1];
            }
            arr[j] = tempval;
        }
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
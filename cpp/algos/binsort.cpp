#include "iostream"

using namespace std;

int findloc(int * arr, int val, int start, int end){
   if(end<=start){
       if(val>arr[start]){
           return start+1;
       }
       return start;
   }

   int index = (start+end)/2;

   if(val>arr[index]){
       return findloc(arr, val, index+1, end);
   }
   return findloc(arr, val, start, index-1); 
}

void solve(int * arr, int size){
    
    for(int i=1;i<size;i++){
        int temp = arr[i];
        int loc = findloc(arr,temp,0,i-1);
        int j = i-1;
        while(j>=loc){
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
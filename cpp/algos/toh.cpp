#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

vector<vector<int>> solve(int numToMove, int from, int to, int third, vector<vector<int>> arr){
    if(numToMove==0){
        return arr;
    }
    arr = solve(numToMove-1, from, third, to, arr);
    arr[to].push_back(arr[from][arr[from].size()-1]);
    arr[from].pop_back();
    return solve(numToMove-1,third,to,from,arr);
}

int main(){

    std::vector<vector<int>> arr {{7,7,6,5,4,3,2,1},{},{}};
    cout<<"start:"<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    vector<vector<int>> res = solve(arr[0].size(),0,2,1,arr);
    cout<<"end:"<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
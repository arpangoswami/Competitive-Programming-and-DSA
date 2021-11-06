#include<iostream>
using namespace std;
void search_sorted(int **arr,int m,int n,int target){
    int i = 0,j = n-1;
    //cout<<initial<<endl;
    while(i<m && j>=0){
        if(arr[i][j] == target){
            cout<<1<<endl;
            return;
        }
        else if(target>arr[i][j]){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<0<<endl;
    return;
}
int main(void) {
    int n,m;
    cin>>n>>m;
    int **arr = new int* [m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    //cout<<-1121221<<endl;
    search_sorted(arr,m,n,target);
    for(int i=0;i<m;i++){
        delete []arr[i];
    }
    delete []arr;
}

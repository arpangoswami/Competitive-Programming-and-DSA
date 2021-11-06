#include<iostream>
using namespace std;
void spiral_print(int **arr,int m,int n){
    if(m<=0 || n<=0){
        return;
    }
    if(m==1){
        for(int i=0;i<n;i++){
            cout<<arr[0][i]<<", ";
        }
        return;
    }
    if(n==1){
       for(int i=0;i<n;i++){
            cout<<arr[i][0]<<", ";
        }
        return;
    }
    for(int i=0;i<m-1;i++){
        cout<<arr[i][0]<<", ";
    }
    for(int j=0;j<n-1;j++){
        cout<<arr[m-1][j]<<", ";
    }
    for(int i=m-1;i>=1;i--){
        cout<<arr[i][n-1]<<", ";
    }
    for(int j=n-1;j>=1;j--){
        cout<<arr[0][j]<<", ";
    }
    int **arr1 = new int*[m-2];
    for(int i=0;i<n-2;i++){
        arr1[i] = new int[n-2];
    }
    for(int i=0;i<m-2;i++){
        for(int j=0;j<n-2;j++){
            arr1[i][j] = arr[i+1][j+1];
        }
    }
    /*for(int i=0;i<m;i++){
        delete []arr[i];
    }
    delete []arr;*/
    spiral_print(arr1,m-2,n-2);
}
int main(void){
    int m,n;
    cin>>m>>n;
    int **arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    spiral_print(arr,m,n);
    cout<<"END";
    for(int i=0;i<m;i++){
        delete []arr[i];
    }
    delete []arr;
}

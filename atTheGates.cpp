#include<bits/stdc++.h>
using namespace std;
void change(char *arr,int idx){
    for(int i=0;i<idx;i++){
        if(arr[i]=='H'){
            arr[i] = 'T';
        }
        else{
            arr[i] = 'H';
        }
    }
}
/*void print(char *arr,int idx){
    for(int i=0;i<idx;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}*/
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        char* arr = new char[n];
        //int rem = (n-k);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=k;i++){
            if(arr[n-i] == 'H')
                change(arr,n-i);
        }
        int c = 0;
        for(int i=0;i<(n-k);i++){
            if(arr[i]=='H'){
                c++;
            }
        }
        cout<<c<<endl;
        delete []arr;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1 || n==2){
            delete []arr;
            cout<<"Yes"<<endl;
            continue;
        }

    }
}

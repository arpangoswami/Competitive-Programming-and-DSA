#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int minXor = INT_MAX;
        for(int i=0;i<n-1;i++){
            int curr_xor = arr[i]^arr[i+1];
            minXor = min(minXor,curr_xor);
        }
        delete []arr;
        cout<<minXor<<endl;
    }
}

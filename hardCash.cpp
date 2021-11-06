#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long coinToPick = 0;
        for(int i=0;i<(n-1);i++){
            coinToPick+=(long)(arr[i]%k);
        }
        int x = arr[n-1]/k;
        if((x+1)*k-arr[n-1]>coinToPick){
            coinToPick+=(long)(arr[n-1]%k);
        }
        else{
            coinToPick-=(long)((x+1)*k-arr[n-1]);
            coinToPick%=(long)k;
        }
        cout<<coinToPick<<endl;
        delete []arr;
    }
}

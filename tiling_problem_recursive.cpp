#include<iostream>
#define mod 1000000007
using namespace std;
long tiling(int n,int m,long arr[]){
    if(n<m){
        arr[n] = 1;
        return 1;
    }
    if(arr[n]!=0)
        return arr[n];
    long ans = (tiling(n-1,m,arr)%mod+tiling(n-m,m,arr)%mod)%mod;
    arr[n] = ans;
    return arr[n];
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        if(n<m){
            cout<<1<<endl;
            continue;
        }
        long *arr = new long[n+1]();
        long ans = tiling(n,m,arr);
        cout<<ans<<endl;
        delete []arr;
    }
}

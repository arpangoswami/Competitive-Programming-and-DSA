#include<iostream>
#define mod 1000000007
using namespace std;
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
        for(int i=0;i<m;i++){
            arr[i] = 1;
        }
        for(int i=m;i<=n;i++){
            arr[i] = (arr[i-1]%mod+arr[i-m]%mod)%mod;
        }
        cout<<arr[n]%mod<<endl;
        delete []arr;
    }
}

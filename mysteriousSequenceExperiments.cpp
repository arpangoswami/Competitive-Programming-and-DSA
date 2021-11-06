#include<bits/stdc++.h>
using namespace std;
const long mod = 1000000007;
int commonBitsCount(int a,int b){
    int c = 0;
    int i=0;
    while(a>0 || b>0){
        if(((a>>i)&1) && (b>>i)&1){
            c++;
        }
        i++;
    }
    return c;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n]();
        int *dp = new int[n]();
        for(int i=0;i<n;i++) cin>>arr[i];
        dp[0] = 1;
        for(int i=1;i<n;i++){
            int bit = commonBitsCount(arr[i],arr[i-1]);
            dp[i] = ((dp[i-1]%mod) * ((long)(1<<bit)%mod))%mod;
        }
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        cout<<dp[n-1]<<endl;
        delete []arr;
        delete []dp;
    }
}

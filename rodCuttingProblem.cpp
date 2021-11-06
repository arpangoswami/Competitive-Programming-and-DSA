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
        int *dp = new int[n+1]();
        dp[1] = arr[0];
        for(int i=2;i<=n;i++){
            dp[i] = arr[i-1];
            for(int j=1;j<=(i/2);j++){
                dp[i] = max(dp[i],dp[j]+dp[i-j]);
            }
        }
        cout<<dp[n]<<endl;
        delete []dp;
        delete []arr;
    }
}

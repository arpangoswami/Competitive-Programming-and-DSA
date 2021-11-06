#include<bits/stdc++.h>
using namespace std;
long *dp;
int main(){
    long n;
    cin>>n;
    dp = new long [n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for(long i=5;i<=n;i++){
        dp[i] = max(i,dp[i/2]+dp[i/3]+dp[i/4]);
    }
    cout<<dp[n]<<endl;
    delete []dp;
    return 0;
}

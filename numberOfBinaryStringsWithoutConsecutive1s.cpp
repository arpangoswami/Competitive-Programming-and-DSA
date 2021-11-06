#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    long dp[90][2];
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i=1;i<90;i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    while(test--){
        int n;
        cin>>n;
        cout<<dp[n-1][0]+dp[n-1][1]<<endl;
    }
    return 0;
}

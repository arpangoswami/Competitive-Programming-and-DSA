#include <iostream>
#include <cstring>
using namespace std;
int dp[105][105][2];
int adjBitCount(int n,int k,int last){
    if(n == 0){
        if(k == 0) return 1;
        return 0;
    }
    if(dp[n][k][last]!=-1){
        return dp[n][k][last];
    }
    int val = -1;
    if(last == 1){
        val = adjBitCount(n-1,k-1,1) + adjBitCount(n-1,k,0);
    }
    else{
        val = adjBitCount(n-1,k,1) + adjBitCount(n-1,k,0);
    }
    return dp[n][k][last] = val;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        int t,n,k;
        cin>>t>>n>>k;
        if(k>=n){
            cout<<t<<" "<<0<<endl;
            continue;
        }
        memset(dp,-1,sizeof(dp));
        int ans = adjBitCount(n-1,k,1);
        ans+=adjBitCount(n-1,k,0);
        cout<<t<<" "<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105];
int maxAscii(int n,int m,int k,string a,string b){
    if(dp[n][m][k]!=-1){
        return dp[n][m][k];
    }
    if(n == 0 || m == 0){
        if(k > 0){
            return -10000000;
        }
        return 0;
    }
    else if(a[n-1] == b[m-1]){
        if(k>0)
            return dp[n][m][k] = max(a[n-1] + maxAscii(n-1,m-1,k-1,a,b),max(maxAscii(n-1,m,k,a,b),maxAscii(n,m-1,k,a,b)));
        return 0;
    }    
    return dp[n][m][k] = max(maxAscii(n-1,m,k,a,b),maxAscii(n,m-1,k,a,b));
}
int main(){
    int test;
    cin>>test;
    while(test--){
        string a,b;
        cin>>a>>b;
        int k;
        cin>>k;
        memset(dp,-1,sizeof(dp));
        cout<<max(0,maxAscii(a.size(),b.size(),k,a,b))<<endl;
    }
    return 0;
}
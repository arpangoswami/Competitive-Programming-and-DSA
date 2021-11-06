#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll countSeq(int openTillNow,int closeTillNow,int i,const unordered_set<int> &open,ll **dp,int n){
    if(dp[openTillNow][closeTillNow]!=-1){
        return dp[openTillNow][closeTillNow];
    }
   	if(i == 2*n){
        return dp[openTillNow][closeTillNow] = 1;
    }
    if(open.count(i)){
        if(openTillNow<n){
            return dp[openTillNow][closeTillNow] = countSeq(openTillNow+1,closeTillNow,i+1,open,dp,n);
        }
        return 0;
    }
    else if(openTillNow == closeTillNow){
        return dp[openTillNow][closeTillNow] = countSeq(openTillNow+1,closeTillNow,i+1,open,dp,n);
    }
    else if(openTillNow == n && closeTillNow<n){
        return dp[openTillNow][closeTillNow] = countSeq(openTillNow,closeTillNow+1,i+1,open,dp,n);
    }
    return dp[openTillNow][closeTillNow] = countSeq(openTillNow+1,closeTillNow,i+1,open,dp,n) + countSeq(openTillNow,closeTillNow+1,i+1,open,dp,n);
}
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        unordered_set<int> open;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            open.insert(x-1);
        }
        ll **dp = new ll *[n+2];
        for(int i=0;i<=(n+1);i++){
            dp[i] = new ll [n+2];
            for(int j=0;j<=(n+1);j++){
                dp[i][j] = -1;
            }
        }
        ll numseq = countSeq(0,0,0,open,dp,n);
        cout<<numseq<<endl;
        for(int i=0;i<=n;i++){
            delete []dp[i];
        }
        delete []dp;
    }
    return 0;
}
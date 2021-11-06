#include<bits/stdc++.h>
using namespace std;
int dp[201][201][201];
int threeStringsLCS(int m,int n,int o,string &s1,string &s2,string &s3){
    if(dp[m][n][o]!=-1){
        return dp[m][n][o];
    }
    int ans = 0;
    if(m==0 || n==0 || o==0){
        ans = 0;
        dp[m][n][o] = 0;
        return ans;
    }
    if(s1[m-1]==s2[n-1] && s2[n-1]==s3[o-1]){
        ans = 1+threeStringsLCS(m-1,n-1,o-1,s1,s2,s3);
    }
    else{
        ans = max(threeStringsLCS(m-1,n,o,s1,s2,s3),max(threeStringsLCS(m,n-1,o,s1,s2,s3),threeStringsLCS(m,n,o-1,s1,s2,s3)));
    }
    dp[m][n][o] = ans;
    return ans;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int ans = threeStringsLCS(s1.size(),s2.size(),s3.size(),s1,s2,s3);
    cout<<ans<<endl;
}

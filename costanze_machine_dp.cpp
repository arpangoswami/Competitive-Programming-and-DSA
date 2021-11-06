#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(void){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    bool flag = true;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'm' || s[i] == 'w'){
            cout<<0<<endl;
            flag = false;
            break;
        }
    }
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1];
        if((s[i-1] == 'n' && s[i-2] == 'n')||(s[i-1] == 'u' && s[i-2] == 'u')){
            dp[i] = (dp[i]%mod + dp[i-2]%mod)%mod;
        }

    }
    if(flag){
        cout<<dp[n]<<endl;
    }
}

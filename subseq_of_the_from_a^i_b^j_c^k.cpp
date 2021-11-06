
#include<bits/stdc++.h>
using namespace std;

int fun(string &str);
int dp[1001][3];
const int mod = 1e9+7;
int solve(int i,int letter,string &s){
    if(i == -1){
        if(letter == 0){
            return 1;
        }
        return 0;
    }
    if(dp[i][letter]!=-1){
        return dp[i][letter];
    }
    int ans = 0;
    if(letter == 2){
        if(s[i] == 'c'){
            int temp = solve(i-1,2,s);
            ans+=(2*temp);
            ans%=mod;
        }else if(s[i] == 'b'){
            int t1 = solve(i-1,1,s);
            int t2 = solve(i-1,2,s);
            ans+=t1;
            ans%=mod;
            ans+=t2;
            ans%=mod;
        }else if(s[i] == 'a'){
            ans += solve(i-1,2,s);
        }
    }else if(letter == 1){
        if(s[i] == 'b'){
            int temp = solve(i-1,1,s);
            ans+=(2*temp);
            ans%=mod;
        }else if(s[i] == 'a'){
            int t1 = solve(i-1,0,s);
            int t2 = solve(i-1,1,s);
            ans+=t1;
            ans%=mod;
            ans+=t2;
            ans%=mod;
        }else if(s[i] == 'c'){
            ans+=solve(i-1,1,s);
        }
    }else if(letter == 0){
        if(s[i] == 'a'){
            int temp = solve(i-1,0,s);
            ans+=(2*temp);
            ans%=mod;
        }else if(s[i] == 'b' || s[i] == 'c'){
            ans+=solve(i-1,0,s);
        }
    }
    return dp[i][letter] = (ans%=mod);
}
int fun(string &s) {
    //code here
    memset(dp,-1,sizeof(dp));
    int n = s.size();
    int ans = 0;
    for(int i=n-1;i>=2;i--){
        if(s[i] == 'c'){
            ans+=solve(i-1,2,s);
            //cout<<"ans: "<<ans<<" i: "<<i<<"\n";
            ans%=mod;
        }
    }
    return ans;
}


// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends
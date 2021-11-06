#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int solve(int i,int j,int m,int n,string &s,string &t,vector<vector<int>> &dp){
	if(i == m || j == n){
		if(i == m){
			return n - j;
		}
		return m - i;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(s[i] == t[j]){
		return dp[i][j] = solve(i+1,j+1,m,n,s,t,dp);
	}
	int ans1 = 1 + solve(i+1,j+1,m,n,s,t,dp),ans2 = 1 + solve(i+1,j,m,n,s,t,dp),ans3 = 1 + solve(i,j+1,m,n,s,t,dp);
	return dp[i][j] = min({ans1,ans2,ans3});
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s,t;
	cin>>s>>t;
	int m = s.size(),n = t.size();
	vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
	cout<<solve(0,0,m,n,s,t,dp)<<endl;
	return 0;
}
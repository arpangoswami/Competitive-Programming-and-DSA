#include <bits/stdc++.h>
#define int long long
using namespace std;
bool own[11][101];
int dp[101][1024];
int n;
const int mod = 1e9 + 7;
int solve(int shirt,int mask){
	if(mask == (1 << n) - 1){
		return 1;
	}
	if(shirt > 100){
		return 0;
	}
	if(dp[shirt][mask] != -1){
		return dp[shirt][mask];
	}
	int ans = 0;
	for(int i=0;i<10;i++){
		if(mask & (1 << i)){
			continue;
		}
		if(own[i][shirt]){
			ans += solve(shirt + 1,mask | (1 << i));
			ans %= mod;
		}
	}
	ans += solve(shirt + 1,mask);
	ans %= mod;
	return dp[shirt][mask] = ans;
}
void solveQuestion(){
	memset(dp,-1,sizeof(dp));
	memset(own,0,sizeof(own));
	cin >> n;
	string s;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,s);
		stringstream ss(s);
		int val;
		while(ss >> val){
			own[i][val] = true;
		}
	}
	cout<<solve(1,0)<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
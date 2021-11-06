#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[101][101];
string s;
int solve(int i,int bal,int n){
	if(bal < 0){
		return 0;
	}
	if(i == n){
		if(bal == 0){
			return 1;
		}
		return 0;
	}
	if(dp[i][bal] != -1){
		return dp[i][bal];
	}
	if(s[i] == '('){
		return dp[i][bal] = solve(i+1,bal+1,n);
	}else if(s[i] == ')'){
		if(bal == 0){
			return dp[i][bal] = 0;
		}
		return dp[i][bal] = solve(i+1,bal-1,n);
	}else{
		if(bal == 0){
			return dp[i][bal] = solve(i+1,bal+1,n);
		}else{
			return dp[i][bal] = solve(i+1,bal+1,n) | solve(i+1,bal-1,n);
		}
	}
}
void solveQuestion(){
	
	cin >> s;
	int n = s.size();
	if(n % 2 == 1){
		cout<<"NO"<<'\n';
		return;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	int ans = solve(0,0,n);
	if(ans){
		cout<<"YES"<<'\n';
	}else{
		cout<<"NO"<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
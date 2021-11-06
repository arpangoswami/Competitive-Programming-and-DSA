#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
int n;
vector<int> arr[2];
int dp[100001][2];
int solve(int i,int row){
	if(i == n){
		return 0;
	}
	if(dp[i][row] != -1){
		return dp[i][row];
	}
	int &ans = dp[i][row];
	ans = 0;
	return ans = max(solve(i+1,row),(arr[row][i] + solve(i+1,row ^ 1))%MOD);
}
void solveQuestion(){
	cin >> n;
	int ans = 0;
	arr[0].resize(n);
	arr[1].resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[0][i];
	}
	for(int i=0;i<n;i++){
		cin >> arr[1][i];
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	for(int i=0;i<n;i++){
		ans = max(arr[0][i] + solve(i+1,1),ans);
		ans = max(arr[1][i] + solve(i+1,0),ans);
	}
	cout << ans % MOD << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
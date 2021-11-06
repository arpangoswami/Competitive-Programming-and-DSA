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
int n;
int range[200001][2];
vector<vector<int>> adj_list;
int dp[200001][2][2];
int dfs(int v,int par,int state1,int state2){
	if(dp[v][state1][state2] != -1){
		return dp[v][state1][state2];
	}
	int &ans = dp[v][state1][state2];
	ans = abs(range[par][state1] - range[v][state2]);
	for(int x:adj_list[v]){
		if(x == par){
			continue;
		}
		ans += max(dfs(x,v,state2,1),dfs(x,v,state2,0));
	}
	return ans;
}
void solveQuestion(){
	cin >> n;
	adj_list.clear();
	adj_list.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> range[i][0] >> range[i][1];
	}
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	int ans1 = 0,ans2 = 0;
	for(int x:adj_list[1]){
		ans1 += max(dfs(x,1,0,0),dfs(x,1,0,1));
		ans2 += max(dfs(x,1,1,0),dfs(x,1,1,1));
	}
	cout<<max(ans1,ans2)<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
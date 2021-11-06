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
vector<vector<int>> adj_list;
vector<int> level;
int tim;
int down[200001][21];
void dfs(int x,int par,int lvl){
	level[x] = lvl;
	for(int nb:adj_list[x]){
		if(nb != par){
			dfs(nb,x,lvl+1);
		}
	}
}
int drownNode(int v,int dist){
	for(int i=20;i>=0;i--){
		if((dist >> i)&1){
			if(down[v][1<<i] == 0){
				return 0;
			}
			return 
		}
	}
}
int binaryDown(){

}

int solve(int u,int d){
	int lvl = level[u];
	if(lvl > d){
		return 0;
	}
	return drownNode(u,d-lvl);
}
void solveQuestion(){
	cin >> n;
	adj_list.resize(n+1);
	level.resize(n+1);
	for(int i=2;i<=n;i++){
		int u;
		cin >> u;
		adj_list[u].push_back(i);
		adj_list[i].push_back(u);
	}
	dfs(1,0,0);
	map<pii,int> cacheQuery;
	int q;
	cin >> q;
	while(q--){
		int u,d;
		cin >> u >> d;
		if(cacheQuery.count({u,d})){
			cout << cacheQuery[{u,d}] << "\n";
		}else{
			int ans = solve(u,d);
			cacheQuery[{u,d}] = ans;
			cout << ans << "\n";
		}
	}
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
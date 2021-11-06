#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;

vpi sol;
int n,k;
vector<vector<int>> adj_list;
vector<int> vals;
int cumXor;
bool twoParts(){
	if(cumXor == 0){
		return true;
	}
	return false;
}
int dfs1(int v,int par){
	int x = vals[v];
	for(int nb:adj_list[v]){
		if(nb != par){
			x ^= dfs1(nb,v);
		}
	}
	if(sol.empty() && x == cumXor && v != 1){
		sol.push_back({par,v});
	}
	return x;
}
int dfs2(int v,int par){
	int ans = vals[v];
	for(int x:adj_list[v]){
		if(v == sol[0].ff && x == sol[0].ss){
			continue;
		}
		if(x == par){
			continue;
		}
		ans ^= dfs2(x,v);
	}
	if(sol.size() == 1 && ans == cumXor && v != 1){
		sol.push_back({par,v});
	}
	return ans;
}
bool threeParts(){
	dfs1(1,0);
	if(sol.size() == 1){
		dfs2(1,0);
		if(sol.size() == 2){
			return true;
		}
	}
	return false;
}
void solveQuestion(){
	cin >> n >> k;
	for(auto &v:adj_list){
		v.clear();
	}
	sol.clear();
	adj_list.resize(n+1);
	vals.clear();
	vals.resize(n+1);
	cumXor = 0;
	for(int i=1;i<=n;i++){
		cin >> vals[i];
		cumXor ^= vals[i];
	}
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	if(twoParts()){
		cout<<"YES\n";
		return;
	}
	if(k >= 3 && threeParts()){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
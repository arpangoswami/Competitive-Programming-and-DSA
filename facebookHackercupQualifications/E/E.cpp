#include <bits/stdc++.h>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
vector<int> value;
vector<vi> adj_list;
int dfs(int v,int p){
	int ans = value[v];
	int maxChild = 0;
	for(int x:adj_list[v]){
		if(x == p){
			continue;
		}
		maxChild = max(maxChild,dfs(x,v));
	}
	return (ans + maxChild);
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	value.resize(n+1);
	adj_list.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> value[i];
		adj_list[i].clear();
	}
	
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	if(n == 1 || k == 0){
		cout<<value[1]<<"\n";
		return;
	}
	vector<int> kids;
	for(int x:adj_list[1]){
		kids.push_back(dfs(x,1));
	}
	while(kids.size() < (k+1)){
		kids.push_back(0);
	}
	sort(kids.begin(),kids.end(),greater<int>());
	int ans = value[1];
	for(int i=0;i<=k;i++){
		ans += kids[i];
	}
	cout << ans << "\n";

}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("E_val_input.txt", "r", stdin);

	freopen("E_val_output.txt", "w", stdout);

	#endif

	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}





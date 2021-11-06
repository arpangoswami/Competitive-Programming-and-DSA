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
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int nonBudLeaves;
vector<int> buds;
vector<vector<int>> adj_list;
bool isLeaf(int v){
	return adj_list[v].size() == 1;
}
// void dfsLeaves(int v,int par){
// 	bool leaf = true;
// 	for(int x:adj_list[v]){
// 		if(x == par){
// 			continue;
// 		}
// 		leaf = false;
// 		dfs(x,v);
// 	}
// 	if(leaf){
// 		nonBudLeaves++;
// 	}
// }
void dfs(int v,int par){
	bool bud = true,nonLeaf = false;
	for(int x:adj_list[v]){
		if(x == par){
			continue;
		}
		nonLeaf = true;
		if(!isLeaf(x)){
			bud = false;
		}
		dfs(x,v);
	}
	if(bud && nonLeaf){
		buds.push_back((int)adj_list[v].size()-1);
	}else if(!nonLeaf){
		nonBudLeaves++;
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	adj_list.resize(n+1);
	for(int i=0;i<=n;i++){
		adj_list[i].clear();
	}
	adj_list[1].push_back(0);
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	nonBudLeaves = 0;
	buds.clear();
	dfs(1,0);
	sort(buds.begin(),buds.end(),greater<int>());
	// for(int x:buds){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	int sum = accumulate(buds.begin(),buds.end(),0LL);
	nonBudLeaves -= sum;
	//cout << nonBudLeaves << "\n";
	for(int i=0;i<buds.size();i++){
		//cout<<nonBudLeaves<<" "<<(nonBudLeaves > 0 ? nonBudLeaves - 1 : nonBudLeaves)<<"\n";
		if(nonBudLeaves > 0){
			nonBudLeaves--;
		}
		nonBudLeaves += buds[i];
	}
	cout << nonBudLeaves << "\n";
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
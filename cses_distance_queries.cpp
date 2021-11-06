#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void dfs(int node,int par,int lvl,vector<int> &levels,vector<int> adj_list[]){
	levels[node] = lvl;
	for(int nb:adj_list[node]){
		if(nb != par){
			dfs(nb,node,lvl+1,levels,adj_list);
		}
	}
}
void binary_lifting(int node,int par,vector<int> adj_list[],vector<vector<int>> &up){
	up[node][0] = par;
	for(int i=1;i<20;i++){
		if(up[node][i-1]!=-1)
			up[node][i] = up[up[node][i-1]][i-1];
		else
			up[node][i] = -1;
	}
	for(int nb:adj_list[node]){
		if(nb!=par){
			binary_lifting(nb,node,adj_list,up);
		}
	}
}
int liftNode(int node,int jump_req,vector<vector<int>> &up){
	for(int i=19;i>=0;i--){
		if(node == -1 || jump_req == 0){
			break;
		}
		if(jump_req >= (1 << i)){
			node = up[node][i];
			jump_req -= (1 << i);
		}
	}
	return node;
}
int calDist(int u,int v,vector<vector<int>> &up,vector<int> &levels){
	if(levels[u] < levels[v]){
		swap(u,v);
	}
	int diff = levels[u] - levels[v];
	u = liftNode(u,diff,up);
	if(u == v){
		return diff;
	}
	int ans = diff;
	for(int i=19;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
			ans += (1 << (i + 1));
		}
	}
	return (ans + 2);
}
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	vector<int> adj_list[n+1];
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<vector<int>> up(n+1,vector<int>(20));
	vector<int> levels(n+1);
	binary_lifting(1,-1,adj_list,up);
	dfs(1,-1,0,levels,adj_list);
	while(q--){
		int u,v;
		cin >> u >> v;
		cout<<calDist(u,v,up,levels)<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
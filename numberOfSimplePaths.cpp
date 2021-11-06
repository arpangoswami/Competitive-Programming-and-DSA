#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void dfsCycle(int u,int p,vector<int> adj_list[],vector<int> &color,vector<int> &mark,vector<int> &par,int &cycleNumber){
	if(color[u] == 2){
		return;
	}
	if (color[u] == 1) {
        cycleNumber++;
        int cur = p;
        mark[cur] = cycleNumber;
        while (cur != u) {
            cur = par[cur];
            mark[cur] = cycleNumber;
        }
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : adj_list[u]) {
        if (v == par[u]) {
            continue;
        }
        dfsCycle(v, u, adj_list,color, mark, par, cycleNumber);
    }
    color[u] = 2;
}
void dfs(int sv,int par,vector<int> adj_list[],vector<int> &mark,unordered_set<int> &st){
	st.insert(sv);
	for(int x:adj_list[sv]){
		if(mark[x]){
			continue;
		}
		if(x == par){
			continue;
		}
		dfs(x,sv,adj_list,mark,st);
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> adj_list[n+1];
	vector<int> colors(n+1);
	vector<int> paths(n+1);
	vector<int> parent(n+1);
	vector<int> mark(n+1);
	vector<int> componentSize(n+1);
	for(int i=1;i<=n;i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	int cycleNumber = 0;
	dfsCycle(1, 0, adj_list, colors, mark, parent, cycleNumber);
	// for(int i=1;i<=n;i++){
	// 	cout<<mark[i]<<" ";
	// }
	// cout<<'\n';
	for(int i=1;i<=n;i++){
		if(mark[i]){
			unordered_set<int> st;
			dfs(i,0,adj_list,mark,st);
			int sz = st.size();
			for(int x:st){
				componentSize[x] = sz;
			}
		}
	}
	for(int i=1;i<=n;i++){
		 paths[i] = (componentSize[i]-1) + 2 * (n - componentSize[i]);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += paths[i];
	}
	ans/=2;
	cout<<ans<<'\n';
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
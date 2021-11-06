#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
void dfs(int sv,vector<int> *adj_list,vector<bool> &visited){
	visited[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			dfs(x,adj_list,visited);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i = 0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<bool> visited(n+1,false);
	dfs(1,adj_list,visited);
	vector<pii> roads;
	for(int i=2;i<=n;i++){
		if(!visited[i]){
			roads.push_back({1,i});
			dfs(i,adj_list,visited);
		}
	}
	delete []adj_list;
	cout<<roads.size()<<"\n";
	for(pii x:roads){
		cout<<x.first<<" "<<x.second<<"\n";
	}
	return 0;
}
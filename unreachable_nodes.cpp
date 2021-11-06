#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void dfs(int sv,bool *visited,vector<int> *adj_list){
	visited[sv] = true;
	for(int i=0;i<adj_list[sv].size();++i){
		if(!visited[adj_list[sv][i]]){
			dfs(adj_list[sv][i],visited,adj_list);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int>* adj_list = new vector<int> [n]();
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj_list[u-1].push_back(v-1);
		adj_list[v-1].push_back(u-1);
	}
	bool *visited = new bool[n]();
	int sv;
	cin>>sv;
	dfs(sv-1,visited,adj_list);
	int ans = 0;
	for(int i=0;i<n;++i){
		if(!visited[i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	delete []visited;
	delete []adj_list;
	return 0;
}
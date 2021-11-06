#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void dfs(int sv,vector<bool> &visited,vector<int>* adj_list,int parent_child,int &num){
	visited[sv] = true;
	int own_child = 0;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			own_child++;
		}
	}
	if(own_child>parent_child){
		num++;
	}
	for(int x:adj_list[sv]){
		if(!visited[x]){
			dfs(x,visited,adj_list,own_child,num);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<bool> visited(n+1,false);
	int num = 0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i,visited,adj_list,INT_MAX,num);
		}
	}
	cout<<num<<endl;
	delete []adj_list;
	return 0;
}
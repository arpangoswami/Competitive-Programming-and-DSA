#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool bipartiteMatchingDFS(int sv,vector<int>* adj_list,vector<bool> &visited,vector<int> &color){
	for(int x:adj_list[sv]){
		if(!visited[x]){
			visited[x] = true;
			color[x] = 1 - color[sv];
			if(!bipartiteMatchingDFS(x,adj_list,visited,color)){
				return false;
			}
		}
		else if(color[sv] == color[x]){
			return false;
		}
	}
	return true;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;t++){
		int n,e;
		cin>>n>>e;
		vector<bool> visited(n+1);
		vector<int> *adj_list = new vector<int>[n+1];
		vector<int> color(n+1);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		bool flag = true;
		for(int i=1;i<=n && flag;i++){
			if(!visited[i]){
				color[i] = 0;
				visited[i] = true;
				flag = bipartiteMatchingDFS(i,adj_list,visited,color);
			}
		}
		cout<<"Scenario #"<<t<<":\n";
		if(flag){
			cout<<"No suspicious bugs found!"<<endl;
		}else{
			cout<<"Suspicious bugs found!"<<endl;
		}
		delete []adj_list;
	}
	return 0;
}
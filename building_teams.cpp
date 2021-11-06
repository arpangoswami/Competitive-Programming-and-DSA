#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(int sv,int col,vector<int> &color,vector<int>* adj_list){
	color[sv] = col;
	int nb = (col == 1)?2:1;
	for(int x:adj_list[sv]){
		if(color[x] == -1){
			bool f = dfs(x,nb,color,adj_list);
			if(!f){
				return false;
			}
		}else if(color[x] == col){
			return false;
		}
	}
	return true;
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
	vector<int> color(n+1,-1);
	bool flag = true;
	for(int i=1;i<=n && flag;i++){
		if(color[i] == -1){
			flag = dfs(i,1,color,adj_list);
		}
	}
	if(!flag){
		cout<<"IMPOSSIBLE"<<"\n";
	}else{
		for(int i=1;i<=n;i++){
			cout<<color[i]<<" ";
		}
	}
	delete []adj_list;
	return 0;
}
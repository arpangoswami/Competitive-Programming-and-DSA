#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int dfs(int sv,vector<int> *adj_list,vector<bool> &visited,vector<int> &child){
	int ans = 0;
	visited[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			ans+=(1 + dfs(x,adj_list,visited,child));
		}
	}
	return child[sv] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i=2;i<=n;i++){
		int v;
		cin>>v;
		adj_list[i].push_back(v);
		adj_list[v].push_back(i);
	}
	vector<bool> visited(n+1,false);
	vector<int> child(n+1,0);
	int x = dfs(1,adj_list,visited,child);
	for(int i=1;i<=n;i++){
		cout<<child[i]<<" ";
	}
	return 0;
}
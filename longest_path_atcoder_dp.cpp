/*https://atcoder.jp/contests/dp/tasks/dp_g*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dfs(int sv,vector<int> *adj_list,vector<bool> &visited,vector<int> &dp){
	int maxm = 0;
	visited[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			maxm = max(maxm,1+dfs(x,adj_list,visited,dp));
		}
		else{
			maxm = max(maxm,1+dp[x]);
		}
	}
	return dp[sv] = maxm;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> *adj_list = new vector<int>[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
	}
	vector<bool> visited(n+1,false);
	vector<int> dp(n+1,0);
	int maxm = 0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			maxm = max(maxm,dfs(i,adj_list,visited,dp));
		}
	}
	cout<<maxm<<endl;
	delete []adj_list;
	return 0;
}
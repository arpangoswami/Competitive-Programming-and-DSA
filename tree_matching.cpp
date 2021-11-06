#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int dp[200001][2];
void solve(int node,int parent,vector<int> *adj_list){
	bool leaf = true;
	dp[node][0] = dp[node][1] = 0;
	vector<int> prefix;
	vector<int> suffix;
	for(int x:adj_list[node]){
		if(x!=parent){
			leaf = false;
			solve(x,node,adj_list);
		}
	}
	if(leaf){
		return;
	}
	for(int x:adj_list[node]){
		if(x!=parent){
			prefix.push_back(max(dp[x][0],dp[x][1]));
			suffix.push_back(max(dp[x][0],dp[x][1]));
		}
	}
	for(int i=1;i<(int)prefix.size();i++){
		prefix[i] += prefix[i-1];
	}
	for(int i=(int)suffix.size()-2;i>=0;i--){
		suffix[i] += suffix[i+1];
	}
	dp[node][0] = suffix[0];
	int i = 0;
	for(int x:adj_list[node]){
		if(x!=parent){
			int lchild = (i == 0) ? 0 : prefix[i-1];
			int rchild = (i == (int)suffix.size()-1) ? 0 : suffix[i+1];
			dp[node][1] = max(dp[node][1],1 + lchild + rchild + dp[x][0]);
			i++;
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	solve(1,0,adj_list);
	cout<<max(dp[1][0],dp[1][1]);
	delete []adj_list;
	return 0;
}
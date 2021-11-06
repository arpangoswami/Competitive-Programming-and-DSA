#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int sz = 2e5+1;
vector<int> adj_list[sz];
int dp[sz][2];
int n,m;
vector<bool> visited;
vector<int> dist;
void bfs(int sv){
	queue<int> q;
	q.push(sv);
	dist[sv] = 0;
	visited[sv] = true;
	while(!q.empty()){
		//cout<<"yolo"<<'\n';
		int tp = q.front();
		q.pop();
		for(int x:adj_list[tp]){
			if(!visited[x]){
				//cout<<"lmao"<<'\n';
				dist[x] = 1 + dist[tp];
				visited[x] = true;
			}
		}
	}
}
int solve(int v,int state){
	if(v == 1){
		return dp[v][state] = 0;
	}
	if(dp[v][state] != -1){
		return dp[v][state];
	}
	if(state == 1){
		int ans = dist[v];
		for(int x:adj_list[v]){
			if(dist[x] < dist[v]){
				ans = min(ans,solve(x,1));
			}
		}
		return dp[v][state] = ans;
	}else{
		int ans = dist[v];
		for(int x:adj_list[v]){
			if(dist[x] >= dist[v]){
				ans = min(ans,solve(x,1));
			}else{
				ans = min(ans,solve(x,0));
			}
		}
		return dp[v][state] = ans;
	}
}
void solveQuestion(){
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	visited.resize(n+1);
	for(int i=1;i<=n;i++){
		visited[i] = false;
		adj_list[i].clear();
	}
	dist.resize(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
	}
	bfs(1);
	for(int i=1;i<=n;i++){
		solve(i,0);
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i][0]<<" ";
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
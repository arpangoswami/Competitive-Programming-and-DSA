#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

vector<vector<int>> adj_list;

bool detectCycle(int v,vector<bool> &visited,vector<bool> &recSt){
	visited[v] = true;
	recSt[v] = true;
	for(int x:adj_list[v]){
		if(!visited[x] && detectCycle(x,visited,recSt)){
			return true;
		}else if(recSt[x]){
			return true;
		}
	}
	recSt[v] = false;
	return false;
}

void solveQuestion(){
	int n;
	cin >> n;
	adj_list.resize(n+1);
	for(int i=1;i<=n;i++){
		adj_list[i].clear();
	}
	vector<int> indegree(n+1);
	for(int i=1;i<=n;i++){
		int cnt;
		cin >> cnt;
		for(int j=0;j<cnt;j++){
			int u;
			cin >> u;
			adj_list[u].push_back(i);
			indegree[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		sort(adj_list[i].begin(),adj_list[i].end());
	}
	vector<bool> visited(n+1);
	vector<bool> recStack(n+1);
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			bool f = detectCycle(i,visited,recStack);
			if(f){
				cout<<"-1\n";
				return;
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	vector<int> readings(n+1,1);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x:adj_list[v]){
			indegree[x]--;
			if(x > v){
				readings[x] = max(readings[x],readings[v]);
			}else{
				readings[x] = max(readings[x],1 + readings[v]);
			}
			if(indegree[x] == 0){
				q.push(x);
			}
		}
	}
	int ans = 1;
	for(int i=1;i<=n;i++){
		ans = max(ans,readings[i]);
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
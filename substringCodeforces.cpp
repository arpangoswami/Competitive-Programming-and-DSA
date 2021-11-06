// https://codeforces.com/problemset/problem/919/d

#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> indegree;
vector<bool> recStack;
vector<int> topoSort;
string value;
bool detectCycle(int v){
	visited[v] = true;
	recStack[v] = true;
	for(int x:adj_list[v]){
		if(!visited[x] && detectCycle(x)){
			return true;
		}else if(recStack[x]){
			return true;
		}
	}
	recStack[v] = false;
	return false;
}
void topologicalSort(int N){
	queue<int> q;
	for(int i=0;i<N;i++){
		if(!indegree[i]){
			q.push(i);
			topoSort.push_back(i);
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x:adj_list[v]){
			indegree[x]--;
			if(!indegree[x]){
				q.push(x);
				topoSort.push_back(x);
			}
		}
	}
}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	adj_list.resize(n);
	visited.resize(n);
	indegree.resize(n);
	recStack.resize(n);
	cin >> value;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		if(u == v){
			cout<<"-1\n";
			return;
		}
		adj_list[u].push_back(v);
		indegree[v]++;
	}
	for(int i=0;i<n;i++){
		if(!visited[i] && detectCycle(i)){
			cout<<"-1\n";
			return;		
		}
	}
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	topologicalSort(n);
	vector<vector<int>> dp(n,vector<int>(26));
	int ans = 1;
	for(int i=n-1;i>=0;i--){
		int v = topoSort[i];
		for(int x:adj_list[v]){
			for(int j=0;j<26;j++){
				dp[v][j] = max(dp[v][j],dp[x][j]);
			}
		}
		dp[v][value[v] - 'a']++;
		//cout<<"v: "<<v<<" "<<dp[v][value[v] - 'a']<<"\n";
		ans = max(ans,dp[v][value[v] - 'a']);
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
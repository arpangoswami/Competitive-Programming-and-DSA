#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,e;
	cin >> n >> e;
	vector<pii> adj_list[n+1];
	vector<bool> visited(n+1);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,1});
	for(int i=0;i<e;i++){
		int u,v,cost;
		cin >> u >> v >> cost;
		adj_list[u].push_back({v,cost});
	}
	vector<int> distance(n+1,LONG_MAX);
	distance[1] = 0;
	while(!pq.empty()){
		pii node = pq.top();
		pq.pop();
		int v = node.second,dist = node.first;
		if(visited[v]){
			continue;
		}
		visited[v] = true;
		for(pii x:adj_list[v]){
			int nb = x.first,add = x.second;
			if(distance[nb] > dist + add && !visited[nb]){
				distance[nb] = dist + add;
				pq.push({distance[nb],nb});
			}
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<distance[i]<<" ";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
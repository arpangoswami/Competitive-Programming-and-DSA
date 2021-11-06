/*
MST - Minimum Spanning Tree
#mst
Find the minimum spanning tree of the graph.

Input
On the first line there will be two integers N - the number of nodes and M - the number of edges. (1 <= N <= 10000), (1 <= M <= 100000)
M lines follow with three integers i j k on each line representing an edge between node i and j with weight k. The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be <= 1000000.

Output
Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.

Example
Input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

Output:
17*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> wt;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,e;
	cin>>n>>e;
	vector<wt>* adj_list = new vector<wt> [n+1];
	for(int i=0;i<e;i++){
		int u,v;
		ll cost;
		cin>>u>>v>>cost;
		adj_list[u].push_back({cost,v});
		adj_list[v].push_back({cost,u});
	}
	priority_queue<wt,vector<wt>,greater<wt>> pq;
	vector<bool> visited(n+1,false);
	visited[1] = true;
	for(wt x:adj_list[1]){
		pq.push(x);
	}
	ll ans = 0;
	while(!pq.empty()){
		wt x = pq.top();
		pq.pop();
		if(visited[x.second]){
			continue;
		}
		ans+=x.first;
		int node = x.second;
		visited[node] = true;
		for(wt f:adj_list[node]){
			pq.push(f);
		}
	}
	cout<<ans<<endl;
	delete []adj_list;
	return 0;
}
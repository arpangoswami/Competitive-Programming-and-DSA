#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii bfs(int sv,vector<int> *adj_list,int n){
	vector<int> dist(n+1,-1);
	vector<bool> visited(n+1,false);
	visited[sv] = true;
	queue<pii> q;
	q.push({sv,0});
	dist[sv] = 0;
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		int v = top.first, d = top.second;
		dist[v] = d;
		for(int x:adj_list[v]){
			if(!visited[x]){
				visited[x] = true;
				q.push({x,d+1});
			}
		} 
	}
	int maxm = 0,max_v = 0;
	for(int i=1;i<=n;i++){
		if(dist[i]>maxm){
			maxm = dist[i];
			max_v = i;
		}
	}
	return {max_v,maxm};
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<int> dist1(n+1,0);
	vector<int> dist2(n+1,0);
	pii t1 = bfs(1,adj_list,n);
	pii t2 = bfs(t1.first,adj_list,n);
	cout<<t2.second<<"\n";
	delete []adj_list;
	return 0;
}
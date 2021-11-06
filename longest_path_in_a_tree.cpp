/*
PT07Z - Longest path in a tree
#dfs
You are given an unweighted, undirected tree. Write a program to output the length of the longest path (from one node to another) in that tree. The length of a path in this case is number of edges we traverse from source to destination.

Input
The first line of the input file contains one integer N --- number of nodes in the tree (0 < N <= 10000). Next N-1 lines contain N-1 edges of that tree --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u, v <= N).

Output
Print the length of the longest path on one line.

Example
Input:
3
1 2
2 3

Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii bfsMaxDist(int sv,int n,vector<int> *adj_list){
	queue<pii> q;
	q.push({sv,0});
	vector<int> dist(n+1,-1);
	vector<bool> visited(n+1,false);
	dist[sv] = 0;
	visited[sv] = true;
	while(!q.empty()){
		pii node = q.front();
		q.pop();
		int v = node.first,distance = node.second;
		for(int x:adj_list[v]){
			if(!visited[x]){
				dist[x] = distance+1;
				q.push({x,distance+1});
				visited[x] = true;
			}
		}
	}
	int vertex = 0,distance = 0;
	for(int i=1;i<=n;i++){
		if(dist[i]>distance){
			vertex = i;
			distance = dist[i];
		}
	}
	return {vertex,distance};
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> *adj_list = new vector<int>[n+1];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	pii end_point = bfsMaxDist(1,n,adj_list);
	pii dist = bfsMaxDist(end_point.first,n,adj_list);
	cout<<dist.second<<endl;
	delete []adj_list;
	return 0;
}
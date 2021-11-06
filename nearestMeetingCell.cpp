#include <bits/stdc++.h>
using namespace std;
void bfs(int v,vector<int> &dist,vector<int> adj[]){
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	int n = dist.size();
	vector<bool> visited (n,false);
	visited[v] = true;
	while(!q.empty()){
		int ver = q.front();
		q.pop();
		for(int x:adj[ver]){
			if(visited[x]){
				continue;
			}
			dist[x] = 1+dist[ver];
			visited[x] = true;
			q.push(x);
		}
	}
}
/*
1
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
9 2
*/
int solution(vector<int> &arr,int src,int dest){
	int n = arr.size();
	vector<int> adj[n];
	for(int i=0;i<n;i++){
		if(arr[i] != -1){
			adj[i].push_back(arr[i]);
		}
	}
	vector<int> dist1(n,1e9);
	vector<int> dist2(n,1e9);
	bfs(src,dist1,adj);
	bfs(dest,dist2,adj);
	int ans = -1,minDist = 1e9;
	for(int i=0;i<n;i++){
		if(dist2[i] < minDist && dist1[i] < 1e9){
			ans = i;
			minDist = dist2[i];
		}
	}
	return ans;
}
int main(int argc,char **argv){
	int testcases;
	cin >> testcases;
	while(testcases--){
		int array_size;
		cin >> array_size;
		vector<int> arr(array_size);
		for(int i=0;i<array_size;i++){
			cin >> arr[i];
		}
		int src,dest;
		cin >> src >> dest;
		cout << solution(arr,src,dest) << endl;
	}
}
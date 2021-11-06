#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(int sv,int parent,vector<int> *adj_list,vector<int> &arr,vector<bool> &visited){
	visited[sv] = true;
	arr.push_back(sv);
	for(int x:adj_list[sv]){
		if(!visited[x]){
			bool f = dfs(x,sv,adj_list,arr,visited);
			if(f){
				return true;
			}
		}else if(x!=parent){
			arr.push_back(x);
			return true;
		}
	}
	arr.pop_back();
	return false;
}
bool cycleDetection(int sv,int parent,int &vertex,vector<int>* adj_list,vector<bool> &visited){
	visited[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			if(cycleDetection(x,sv,vertex,adj_list,visited)){
				return true;
			}
		}else if(x != parent){
			vertex = sv;
			return true;
		}
	}
	return false;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<bool> visited(n+1,false);
	vector<int> parent_arr(n+1,0);
	bool flag = false;
	int vertex = 0;
	for(int i=1;i<=n && !flag;i++){
		if(!visited[i]){
			flag = cycleDetection(i,0,vertex,adj_list,visited);
		}
	}
	if(!flag){
		cout<<"IMPOSSIBLE";
	}else{
		vector<int> arr;
		for(int i=1;i<=n;i++){
			visited[i] = false;
		}
		dfs(vertex,0,adj_list,arr,visited);
		int i;
		int v = arr.back();
		for(i=0;i<(int)arr.size();i++){
			if(arr[i] == v){
				break;
			}
		}
		cout<<arr.size() - i<<"\n";
		for(;i<(int)arr.size();i++){
			cout<<arr[i]<<" ";
		}
	}
	delete []adj_list;
	return 0;
}
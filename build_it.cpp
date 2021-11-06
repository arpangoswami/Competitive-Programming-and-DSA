#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void dfs(int sv,vector<int> *adj_list,vector<int> &path,vector<bool> &visited,int &cost,int &minCost,int vector<int> &arr){
	cost += arr[sv];
	path.push_back(sv);
	bool f = true;
	for(int x:adj_list[sv]){
		if(visited[x]){
			continue;
		}
		f = false;
		dfs(x,adj_list,path,visited,cost,arr);
	}
	if(!f && cost<minCost){
		minCost = cost;
		
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vector<int> *adj_list = new vector<int>[n+1]();
	vector<int> *adj_listT = new vector<int>[n+1]();
	for(int i=1;i<=n;i++){
		int size;
		cin >> size;
		for(int j=0;j<size;j++){
			int x;
			cin >> x;
			adj_list[x].push_back(i);
			adj_listT[i].push_back(x);
		}
	}
	vector<bool> visited(n+1,false);
	int cost = 0;
	int minCost = LONG_MAX;
	vector<int> path;
	vector<int> &sol;
	dfs(1,adj_listT,path,visited,cost,minCost,arr);
	cout<<cost<<" "<<sol.size()<<"\n";
	for(int i=sol.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
	return 0;
}
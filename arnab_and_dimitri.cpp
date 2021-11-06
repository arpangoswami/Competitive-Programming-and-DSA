#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int path[3][100005];
void path_trace(int vertex,int par,int pathNumber,int idx,int toFind,bool &flag,vector<int> *adj_list){
	for(int x:adj_list[vertex]){
		if(x!=par && !flag){
			path[pathNumber][idx] = x;
			if(x == toFind){
				flag = true;
				path[pathNumber][idx+1] = -1;
				return;
			}
			path_trace(x, vertex, pathNumber, idx+1, toFind, flag, adj_list);
		}
	}
}
int LCA(int a,int b,vector<int> *adj_list){
	if(a == b){
		return a;
	}
	path[1][0] = 1;
	path[2][0] = 1;
	bool flag = false;
	path_trace(1,-1,1,1,a,flag,adj_list);
	flag = false;
	path_trace(1,-1,2,1,b,flag,adj_list);
	int i=0;
	while(path[1][i] == path[2][i]){
		i++;
	}
	return path[1][i-1];
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<int> *adj_list = new vector<int>[n+1]();
		for(int i=0;i<(n-1);i++){
			int u,v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		int u,v;
		cin >> u >> v;
		int vertex = LCA(u,v,adj_list);
		cout << vertex << "\n";
		delete []adj_list;
	}
	return 0;
}
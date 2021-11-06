#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX_SIZE = 1e5+1;
vector<int> adj_list[MAX_SIZE];
int colorsVertices[MAX_SIZE];
//int parent[MAX_SIZE];
int colorsTaken[MAX_SIZE];
vector<int> ans;
void dfs(int v,int parent){
	int col = colorsVertices[v];
	bool add = false;
	if(colorsTaken[col] == 0){
		add = true;
		colorsTaken[col] = 1;
		ans.push_back(v);
	}
	for(int x:adj_list[v]){
		if(x == parent){
			continue;
		}
		dfs(x,v);
	}
	if(add){
		colorsTaken[col] = 0;
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> colorsVertices[i];
	}
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	dfs(1,0);
	sort(ans.begin(),ans.end());
	for(int x:ans){
		cout<<x<<endl;
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
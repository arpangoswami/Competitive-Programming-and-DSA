#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void dfs(int v,vector<int>* adj_list,vector<int> &color,stack<int>* color_stack,vector<int> &ans){
	if(color_stack[color[v]].empty()){
		ans[v] = -1;
	}else{
		ans[v] = color_stack[color[v]].top();
	}
	color_stack[color[v]].push(v);
	for(int x:adj_list[v]){
		dfs(x,adj_list,color,color_stack,ans);
	}
	color_stack[color[v]].pop();
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,c;
	cin>>n>>c;
	vector<int> *adj_list = new vector<int> [n+1];
	stack<int> *color_node = new stack<int> [c+1]; 
	for(int i=2;i<=n;i++){
		int parent;
		cin>>parent;
		adj_list[parent].push_back(i);
	}
	vector<int> color(n+1);
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}
	vector<int> ans(n+1);
	dfs(1,adj_list,color,color_node,ans);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	delete []adj_list;
	delete []color_node;
	return 0;
}
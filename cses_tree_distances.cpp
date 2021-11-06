/*
Tree Distances II
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You are given a tree consisting of n nodes.

Your task is to determine for each node the sum of the distances from the node to all other nodes.

Input

The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.

Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output

Print n integers: for each node 1,2,…,n, the sum of the distances.

Constraints
1≤n≤2⋅105
1≤a,b≤n
Example

Input:
5
1 2
1 3
3 4
3 5

Output:
6 9 5 8 8
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void dfs(int sv,int par,vector<int> &subTreeSize,vector<int> &subTreeAns,vector<int> adj_list[]){
	int subAns = 0,subNodes = 1;
	for(int x:adj_list[sv]){
		if(x!=par){
			dfs(x,sv,subTreeSize,subTreeAns,adj_list);
			subNodes += subTreeSize[x];
			subAns += (subTreeSize[x] + subTreeAns[x]);
		}
	}
	subTreeAns[sv] = subAns;
	subTreeSize[sv] = subNodes;
}
void solve(int sv,int par,int par_ans,int nodes,vector<int> &subTreeAns,vector<int> &subTreeSize,vector<int> adj_list[],vector<int> &ans){
	ans[sv] = subTreeAns[sv] + par_ans + (nodes - subTreeSize[sv]);
	for(int x:adj_list[sv]){
		if(x != par){
			solve(x,sv,ans[sv] - (subTreeSize[x] + subTreeAns[x]),nodes,subTreeAns,subTreeSize,adj_list,ans);
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> adj_list[n+1];
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<int> subTreeAns(n+1);
	vector<int> subTreeSize(n+1);
	dfs(1,0,subTreeSize,subTreeAns,adj_list);
	vector<int> ans(n+1);
	solve(1,0,0,n,subTreeAns,subTreeSize,adj_list,ans);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
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
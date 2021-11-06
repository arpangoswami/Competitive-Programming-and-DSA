/*
https://www.codechef.com/problems/SPTREE

A Special Tree Problem Code: SPTREESolvedSubmit

 
You are given a tree with N nodes (numbered 1 through N). There are K special nodes f1,f2,…,fK in this tree.

We define d(p,q) to be the number of edges on the unique path from node p to node q.

You are given a node a. For each node b from 1 to N, find the maximum value of d(a,u)−d(b,u) where u is a special node, as well as any special node u for which that maximum value is attained.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, K, a.
The second line contains K space-separated integers f1,f2,…,fK.
N−1 lines follow. For each valid i, the i-th of these lines contains two space-separated integers ui and vi denoting an edge of the tree.
Output
For each test case, print two lines.

In the first line print N space-separated integers. For each valid i, the i-th integer should be the maximum value of d(a,u)−d(i,u) where u is a special node.

In the second line print N space-separated integers. For each valid i, the i-th integer should be any special node u for which the maximum of d(a,u)−d(i,u) is attained.

Constraints
1≤T≤200
1≤K≤N≤2⋅105
1≤a≤N
1≤fi≤N for each valid i
fi≠fj for each valid i and j such that i≠j
1≤ui,vi≤N for each valid i
the graph described on the input is a tree
the sum of N over all test cases does not exceed 4⋅105
Subtasks
Subtask #1 (10 points):

T≤11
N≤200
the sum of N over all test cases does not exceed 400
Subtask #2 (20 points):

T≤51
N≤2000
the sum of N over all test cases does not exceed 4000
Subtask #3 (30 points):

It holds that ui=i, vi=i+1 for each valid i.
Subtask #4 (40 points): original constraints

Sample Input
2
5 1 3
2
1 2
1 3
2 4
2 5
8 3 2
6 5 8
1 2
2 3
2 4
2 5
4 6
5 7
5 8
Sample Output
1 2 0 1 1
2 2 2 2 2
-1 0 -1 1 1 2 0 2
5 5 5 6 5 6 5 8
Explanation
Example case 1: The following picture shows the tree in the first example case with special nodes in bold:



The only special node is the node 2 and a=3. Therefore, the desired maximum is d(a,2)−d(b,2)=d(3,2)−d(b,2)=2−d(b,2) for each node b and it is always attained for the special node u=2.

Example case 2: The following picture shows the tree in the second example case with special nodes bolded:



The special nodes are 6, 5 and 8, and a=2. The maximum values of d(a,u)−d(b,u) (u being a special node) for each b are as follows:

b=1: The maximum value of d(2,u)−d(1,u) is −1 and it is achieved for u=5 since d(2,5)−d(1,5)=1−2=−1.

b=2: The maximum value of d(2,u)−d(2,u) is 0 and it is achieved for u=5 since d(2,5)−d(2,5)=1−1=0.

b=3: The maximum value of d(2,u)−d(3,u) is −1 and it is achieved for u=5 since d(2,5)−d(3,5)=1−2=−1.

b=4: The maximum value of d(2,u)−d(4,u) is 1 and it is achieved for u=6 since d(2,6)−d(4,6)=2−1=1.

b=5: The maximum value of d(2,u)−d(5,u) is 1 and it is achieved for u=5 since d(2,5)−d(5,5)=1−0=1.

b=6: The maximum value of d(2,u)−d(6,u) is 2 and it is achieved for u=6 since d(2,6)−d(6,6)=2−0=2.

b=7: The maximum value of d(2,u)−d(7,u) is 0 and it is achieved for u=5 since d(2,5)−d(7,5)=1−1=0.

b=8: The maximum value of d(2,u)−d(8,u) is 2 and it is achieved for u=8 since d(2,8)−d(8,8)=2−0=2.
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
const int sz = 2e5+5;
void dfs1(int node, int par, vector<int> &specialNodes, vector<int> &specialNodeInSubTree, int lvl, vector<int> &levels, vector<int> adj_list[]) {
	levels[node] = lvl;
	if(specialNodes[node]){
		specialNodeInSubTree[node] = node;
	}
	for (int nb : adj_list[node]) {
		if (nb != par) {
			dfs1(nb, node, specialNodes, specialNodeInSubTree, lvl + 1, levels, adj_list);
			if(specialNodeInSubTree[nb] != -1){
				specialNodeInSubTree[node] = specialNodeInSubTree[nb];
			}
		}
	}
}
void dfs2(int node,int par,int &deepestParent, vector<int> &deepestNode, vector<int> &specialNodeInSubTree,vector<int> adj_list[]){
	int temp = -1;
	if(specialNodeInSubTree[node] != -1){
		temp = deepestParent;
		deepestParent = node;
	}
	deepestNode[node] = specialNodeInSubTree[deepestParent];
	for(int nb: adj_list[node]){
		if(nb != par){
			dfs2(nb, node, deepestParent, deepestNode, specialNodeInSubTree, adj_list);
		}
	}
	if(temp != -1){
		deepestParent = temp;
	}
}
void binary_lifting(int node, int par, vector<int> adj_list[], vector<vector<int>> &up) {
	up[node][0] = par;
	for (int i = 1; i < 20; i++) {
		if (up[node][i - 1] != -1)
			up[node][i] = up[up[node][i - 1]][i - 1];
		else
			up[node][i] = -1;
	}
	for (int nb : adj_list[node]) {
		if (nb != par) {
			binary_lifting(nb, node, adj_list, up);
		}
	}
}
int liftNode(int node, int jump_req, vector<vector<int>> &up) {
	for (int i = 19; i >= 0; i--) {
		if (node == -1 || jump_req == 0) {
			break;
		}
		if (jump_req >= (1 << i)) {
			node = up[node][i];
			jump_req -= (1 << i);
		}
	}
	return node;
}
int calDist(int u, int v, vector<vector<int>> &up, vector<int> &levels) {
	if (levels[u] < levels[v]) {
		swap(u, v);
	}
	int diff = levels[u] - levels[v];
	u = liftNode(u, diff, up);
	if (u == v) {
		return diff;
	}
	int ans = diff;
	for (int i = 19; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
			ans += (1 << (i + 1));
		}
	}
	return (ans + 2);
}
void solveQuestion(){
	int n, k, targetNode;
	cin >> n >> k >> targetNode;
	vector<int> specialNodes(n+1);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		specialNodes[x] = 1;
	}
	vector<int> adj_list[n + 1];
	for (int i = 0; i < (n - 1); i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<int> specialNodeInSubTree(n + 1, -1);
	vector<vector<int>> up(n + 1, vector<int>(20));
	vector<int> levels(n + 1);
	binary_lifting(targetNode, -1, adj_list, up);
	dfs1(targetNode, -1, specialNodes, specialNodeInSubTree, 0, levels, adj_list);
	vector<int> distances(n + 1);
	vector<int> ansNode(n + 1);
	vector<int> deepestNode(n+1);
	int deepestParent = targetNode;
	dfs2(targetNode, 0, deepestParent, deepestNode, specialNodeInSubTree, adj_list);
	
	for(int i=1;i<=n;i++){
		cout << calDist(targetNode,deepestNode[i],up,levels) - calDist(i,deepestNode[i],up,levels)<<" ";
	}
	cout<<"\n";
	for(int i=1;i<=n;i++){
		cout<<deepestNode[i]<<" ";
	}
	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
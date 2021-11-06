/*No More Cycles Problem Code: NOCYCLE
Solved
Submit

 
 

Given an undirected graph G with N nodes numbered from 1 to N and M edges. Calculate the minimum number of edges from the graph G that needs to be removed such that it has no cycle.

Input
The first line of input contains 2 space separated integers N and M denoting the number of nodes and the number of edges respectively. 
Each of the next M lines contain 2 space separated integers U and V representing a bidirectional edge between U and V.

Output
The output should consist of a single integer denoting the answer to the problem.

Constraints
1 ≤ N,M ≤ 105
1 ≤ U,V ≤ N
There are no self-loops or multiple edges in the graph.
Information to Score Partial Points
For 10% of the score, it is guaranteed that N ≤ 102.
For further 20% of the score, it is guaranteed that N ≤ 104.
For the rest of the 70% of the score, no extra guarantees. That is, N ≤ 105.
Example
Input:
3 3
1 2
2 3
3 1
Output:
1

Input:
6 6
1 2
2 3
3 1
4 5
5 6
6 4
Output:
2
Explanation
Example 1. Removing any 1 of the 3 edges from the graph will remove the one and only cycle from the graph, so the answer is 1.
graph

Example 2. Removing 1 edge among the first 3 edges (forming a single connected component) and another 1 edge among the last 3 edges (forming another connected component) would remove the 2 cycles from the 2 connected components, so the answer is 2.
graph_1

Author:	2★sinhashubham95
Date Added:	12-01-2018
Time Limit:	1 secs
Source Limit:	50000 Bytes
Languages:	CPP14, C, JAVA, PYTH 3.6, PYTH, CS2, ADA, PYPY, TEXT, PAS fpc, RUBY, PHP, NODEJS, GO, TCL, HASK, PERL, SCALA, kotlin, BASH, JS, PAS gpc, BF, LISP sbcl, CLOJ, LUA, D, CAML, rust, ASM, FORT, FS, LISP clisp, swift, SCM guile, PERL6, CLPS, WSPC, ERL, ICK, NICE, PRLG, ICON, PIKE, COB, SCM chicken, SCM qobi, ST, NEM*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int findParent(int x,vector<int> &parent){
	if(x == parent[x]){
		return x;
	}
	int ans = findParent(parent[x],parent);
	parent[x] = ans;
	return ans;
}
void unionRank(int x,int y,vector<int> &parent,vector<int> &rank){
	int x_rep = findParent(x,parent),y_rep = findParent(y,parent);
	if(x_rep == y_rep){
		return;
	}
	if(rank[x_rep] > rank[y_rep]){
		parent[y_rep] = x_rep;
	}else if(rank[y_rep] > rank[x_rep]){
		parent[x_rep] = y_rep;
	}else{
		parent[y_rep] = x_rep;
		rank[x_rep]++;
	}
}
void solveQuestion(){
	int n,e;
	cin >> n >> e;
	vector<int> parent(n+1);
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	int ans = 0;
	vector<int> rank(n+1);
	for(int i=0;i<e;i++){
		int u,v;
		cin >> u >> v;
		if(findParent(u,parent) == findParent(v,parent)){
			ans++;
			continue;
		}else{
			unionRank(u,v,parent,rank);
		}
	}
	cout<<ans<<"\n";
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
/*
PT07Y - Is it a tree
#dfs
You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.

Input
The first line of the input file contains two integers N and M --- number of nodes and number of edges in the graph (0 < N <= 10000, 0 <= M <= 20000). Next M lines contain M edges of that graph --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).

Output
Print YES if the given graph is a tree, otherwise print NO.

Example
Input:
3 2
1 2
2 3

Output:
YES
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool dfs(int sv, vector<int>* adj_list, vector<bool> &visited, int parent) {
	visited[sv] = true;
	for (int x : adj_list[sv]) {
		if (x != parent) {
			if (visited[x]) {
				return false;
			}
			bool f = dfs(x, adj_list, visited, sv);
			if (!f) {
				return false;
			}
		}
	}
	return true;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int v, e;
	cin >> v >> e;
	vector<int> *adj_list = new vector<int> [v + 1]();
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	int cmp = 0;
	bool cycle = false;
	vector<bool> visited(v + 1, false);
	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			bool cycle = dfs(i, adj_list, visited, -1);
			cmp++;
		}
		if (cycle || cmp == 2) {
			break;
		}
	}
	if (cmp == 1 && !cycle && e == v - 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	delete []adj_list;
	return 0;
}
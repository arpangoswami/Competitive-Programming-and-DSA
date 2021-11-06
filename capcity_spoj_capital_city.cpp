// CAPCITY - Capital City
// #scc






// There are N cities in Flatland connected with M unidirectional roads. The cities are numbered from 1 to N. The Flat Circle of Flatland (FCF) wants to set up a new capital city for his kingdom. For security reasons, the capital must be reachable from all other cities of Flatland. FCF needs the list of all candidate cities. You are the chief programmer at FACM (Flat Association for Computing Machinery) responsible for providing the list to FCF as soon as possible.

// Input

 

// The first line of the input file contains two integers։ 1≤N≤100,000 and 1≤M≤200,000. Each of the following M lines contains two integers 1≤A, B≤N denoting a road from A to B.



// Output 



// The output file contains an integer denoting the number of candidate cities followed by the list of candidate cities in increasing order.



// Example



// Input:



// 4 4

// 1 2

// 3 2

// 4 3

// 2 1



// Output:



// 2

// 1 2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
bool check(unordered_set<int>* adj_list, unordered_set<int>* component) {
	for (auto it = component->begin(); it != component->end(); ++it) {
		int vertex = *it;
		for (int x : adj_list[vertex]) {
			if (component->count(x) == 0) {
				return false;
			}
		}
	}
	return true;
}
void dfs1(int sv, unordered_set<int> *adj_list, stack<int> &st, vector<bool> &visited) {
	visited[sv] = true;
	for (int x : adj_list[sv]) {
		if (!visited[x]) {
			dfs1(x, adj_list, st, visited);
		}
	}
	st.push(sv);
}
void dfs2(int sv, unordered_set<int> *adj_listTrans, vector<bool> &visited, unordered_set<int> *component) {
	visited[sv] = true;
	component->insert(sv);
	for (int x : adj_listTrans[sv]) {
		if (!visited[x]) {
			dfs2(x, adj_listTrans, visited, component);
		}
	}
}
void dfs3(int sv, unordered_set<int> *adj_listTrans, vector<bool> &visited) {
	visited[sv] = true;
	for (int x : adj_listTrans[sv]) {
		if (!visited[x]) {
			dfs3(x, adj_listTrans, visited);
		}
	}
}
unordered_set<unordered_set<int>*>* getSCC(unordered_set<int> *adj_list, unordered_set<int>* adj_listTrans, int n) {
	vector<bool> visited(n + 1, false);
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs1(i, adj_list, st, visited);
		}
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
	unordered_set<unordered_set<int>*>* ans = new unordered_set<unordered_set<int>*>();
	while (!st.empty()) {
		int vertex = st.top();
		st.pop();
		if (!visited[vertex]) {
			unordered_set<int>* component = new unordered_set<int>();
			dfs2(vertex, adj_listTrans, visited, component);
			ans->insert(component);
		}
	}
	return ans;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, e;
	cin >> n >> e;
	unordered_set<int> *adj_list = new unordered_set<int>[n + 1]();
	unordered_set<int> *adj_listTrans = new unordered_set<int>[n + 1]();
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].insert(v);
		adj_listTrans[v].insert(u);
	}
	unordered_set<unordered_set<int>*>* output = getSCC(adj_list, adj_listTrans, n);
	unordered_set<int>* possibleAns;
	bool flag = false;
	for (auto it = output->begin(); it != output->end() && !flag; it++) {
		flag = check(adj_list, *it);
		if (flag) {
			possibleAns = *it;
		}
	}
	vector<bool> visited(n + 1, false);
	if (flag) {
		dfs3(*(possibleAns->begin()), adj_listTrans, visited);
		for (int i = 1; i <= n && flag; i++) {
			if (!visited[i]) {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << possibleAns->size() << endl;
		set<int> s;
		for (auto it = possibleAns->begin(); it != possibleAns->end(); ++it) {
			s.insert(*it);
		}
		for (int x : s) {
			cout << x << " ";
		}
		cout << endl;
	}
	else {
		cout << 0 << endl;
	}
	delete []adj_list;
	delete []adj_listTrans;
	return 0;
}
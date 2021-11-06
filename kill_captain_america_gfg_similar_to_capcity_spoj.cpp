// Kill Captain America Submissions: 1254   Accuracy: 18.05%   Difficulty: Hard   Marks: 8
        
// Problems
// Captain America is hiding from Thanos in a maze full of rooms.
// The maze is designed in such a way that the room, within it, leads to another room via gate. Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
// Further provided that, the movement from one room (R1) to another room (R2) is one way(unidirectional) only .
// Now, you being on Thanos side, want to kill Captain America.  

// Input:
// First line of the input contains T, the number of test cases.
// First line of each test case contains n(no of rooms) and m(no of gates).
// Each m line of test case contains p and q denoting room p is connected to room q .

// Output:
// Each new line of the output contains Total no of rooms .

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ n ≤ 30000
// 1 ≤ m ≤ 200000
// 1 ≤ p,q ≤ n

// Example:
// Input:
// 1
// 5 5
// 1 2
// 2 3
// 3 4
// 4 3
// 5 4

// Output:
// 2
 

 

// ** For More Input/Output Examples Use 'Expected Output' option **
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
bool check(vector<int>* adj_list, unordered_set<int>* component) {
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
void dfs1(int sv, vector<int> *adj_list, stack<int> &st, vector<bool> &visited) {
	visited[sv] = true;
	for (int x : adj_list[sv]) {
		if (!visited[x]) {
			dfs1(x, adj_list, st, visited);
		}
	}
	st.push(sv);
}
void dfs2(int sv, vector<int> *adj_listTrans, vector<bool> &visited, unordered_set<int> *component) {
	visited[sv] = true;
	component->insert(sv);
	for (int x : adj_listTrans[sv]) {
		if (!visited[x]) {
			dfs2(x, adj_listTrans, visited, component);
		}
	}
}
void dfs3(int sv, vector<int> *adj_listTrans, vector<bool> &visited) {
	visited[sv] = true;
	for (int x : adj_listTrans[sv]) {
		if (!visited[x]) {
			dfs3(x, adj_listTrans, visited);
		}
	}
}
unordered_set<unordered_set<int>*>* getSCC(vector<int> *adj_list, vector<int>* adj_listTrans, int n) {
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
	int test;
	cin >> test;
	while (test--) {
		int n, e;
		cin >> n >> e;
		vector<int> *adj_list = new vector<int>[n + 1]();
		vector<int> *adj_listTrans = new vector<int>[n + 1]();
		for (int i = 0; i < e; i++) {
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_listTrans[v].push_back(u);
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
		if(flag)
			cout<<possibleAns->size()<<endl;
		else
			cout<<0<<endl;
		delete []adj_list;
		delete []adj_listTrans;
	}
	return 0;
}
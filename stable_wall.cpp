#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool cycleDetection(char sv, int V, map<char, vector<char>>&adj_list, unordered_map<char, bool> &visited, unordered_map<char, bool> &recSt) {
	visited[sv] = true;
	recSt[sv] = true;
	vector<char> v = adj_list[sv];
	for (char c : v) {
		if (!visited[c] && cycleDetection(c, V, adj_list, visited, recSt)) {
			return true;
		}
		else if (recSt[c]) {
			return true;
		}
	}
	recSt[sv] = false;
	return false;
}
bool isCyclic(int V, map<char, vector<char>> &adj_list) {
	unordered_map<char, bool> visited, recSt;
	for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
		visited[it->first] = false;
		recSt[it->first] = false;
	}
	for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
		if (!visited[it->first]) {
			bool f = cycleDetection(it->first, V, adj_list, visited, recSt);
			if (f) {
				return true;
			}

		}
	}
	return false;
}
vector<char> topoSort(int V, map<char, vector<char>>&adj_list) {
	vector<char> sol;
	unordered_map<char, int> indegree;
	for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
		indegree[it->first] = 0;
	}
	for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
		char c = it->first;
		for (char v : adj_list[c]) {
			indegree[v]++;
		}
	}
	queue<char> q;
	for (auto it = indegree.begin(); it != indegree.end(); ++it) {
		if (it->second == 0) {
			q.push(it->first);
		}
	}
	while (!q.empty()) {
		char sv = q.front();
		sol.push_back(sv);
		q.pop();
		for (char c : adj_list[sv]) {
			indegree[c]--;
			if (indegree[c] == 0) {
				q.push(c);
			}
		}
	}
	return sol;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		int m, n;
		cin >> m >> n;
		vector<string> board(m);
		unordered_set<char> vertices;
		map<char, vector<char>> adj_list;
		for (int i = 0; i < m; i++) {
			cin >> board[i];
			for (int j = 0; j < n; j++) {
				vertices.insert(board[i][j]);
			}
		}
		bool flag = true;
		for (int i = m - 2; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != board[i + 1][j]) {
					flag = false;
					vector<char> v = adj_list[board[i + 1][j]];
					v.push_back(board[i][j]);
					adj_list[board[i + 1][j]] = v;
				}
				vertices.insert(board[i][j]);
			}
		}
		if (!flag) {
			int V = vertices.size();
			bool flag = isCyclic(V, adj_list);
			if (flag == true) {
				cout << "Case #" << t << ":" << " " << -1 << "\n";
			}
			else {
				vector<char> top = topoSort(V, adj_list);
				string ans;
				for (int i = 0; i < top.size(); i++) {
					ans.push_back(top[i]);
					vertices.erase(top[i]);
				}
				if (vertices.size() > 0) {
					for (auto it = vertices.begin(); it != vertices.end(); it++) {
						ans.push_back(*it);
					}
				}
				cout << "Case #" << t << ":" << " " << ans << "\n";
			}
		}
		else {
			string ans;
			for (char c : vertices) {
				ans.push_back(c);
			}
			cout << "Case #" << t << ":" << " " << ans << "\n";
		}
	}
	return 0;
}
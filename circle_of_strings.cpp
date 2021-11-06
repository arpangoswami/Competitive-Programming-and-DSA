#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool canCycle(int idx, string current, const string &first, int need, int curr_size, const vector<string> &vertices, const vector<int> adj[], vector<bool> &taken) {
	if (curr_size == need) {
		if (current.back() == first[0]) {
			return true;
		}
		return false;
	}
	taken[idx] = true;
	for (int j = 0; j < adj[idx].size(); j++) {
		if (!taken[adj[idx][j]]) {
			bool canSolve = canCycle(adj[idx][j], vertices[adj[idx][j]], first, need, curr_size + 1, vertices, adj, taken);
			if (canSolve) {
				return true;
			}
		}
	}
	taken[idx] = false;
	return false;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<string> vertices(n);
		vector<bool> taken(n, false);
		unordered_map<char, vector<string>> first_letter;
		for (int i = 0; i < n; i++) {
			cin >> vertices[i];
			char begin = vertices[i][0];
			first_letter[begin].push_back(vertices[i]);
		}
		vector<int> adj[n];
		for (int i = 0; i < vertices.size(); i++) {
			char back = vertices[i][vertices[i].size() - 1];
			for (int j = 0; j < n; j++) {
				if (j != i && back == vertices[j][0]) {
					adj[i].push_back(j);
				}
			}
		}
		bool flag = false;
		flag = canCycle(0, vertices[0], vertices[0], n, 1, vertices, adj, taken);
		cout << flag << "\n";
	}
	return 0;
}
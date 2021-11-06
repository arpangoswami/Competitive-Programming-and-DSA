#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int bfs(int sv, vector<bool> &visited, vector<int>* adj_list,vector<int> &distance, int n) {
	queue<pii> q;
	q.push({sv, 0});
	visited[sv] = true;
	distance[sv] = 0;
	while (!q.empty()) {
		pii val = q.front();
		q.pop();
		int node = val.first;
		int dist = val.second;
		for (int x : adj_list[node]) {
			if (!visited[x]) {
				distance[x] = dist + 1;
				q.push({x, dist + 1});
				visited[x] = true;
			}
		}
	}
	int maximum = -1, vertex = sv;
	for (int i = 1; i <= n; i++) {
		if (distance[i] > maximum) {
			maximum = distance[i];
			vertex = i;
		}
	}
	return vertex;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int>* adj_list = new vector<int> [n + 1]();
	for (int i = 0; i < (n - 1); i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<bool> visited(n + 1, false);
	vector<int> distance(n + 1, -1);

	int sv = 1;
	int x = bfs(sv, visited, adj_list, distance, n);
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		distance[i] = -1;
	}
	int y = bfs(x, visited, adj_list, distance, n);
	if (x > y) {
		swap(x, y);
	}
	cout << x << " " << y << "\n";
	delete []adj_list;
	return 0;
}
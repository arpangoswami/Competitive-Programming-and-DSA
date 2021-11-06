#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll power(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll smallAns = power(a, b / 2);
	if (b & 1) {
		return smallAns * smallAns * a;
	}
	return smallAns * smallAns;
}
int bfs(vector<int>* adj_list) {
	queue<pii> q;
	vector<bool> visited(101, false);
	visited[1] = true;
	q.push({1, 0});
	while (!q.empty()) {
		pii current = q.front();
		q.pop();
		int vertex = current.first, lvl = current.second;
		if (vertex == 100) {
			return lvl;
		}
		for (int x : adj_list[vertex]) {
			if (!visited[x]) {
				q.push({x, lvl + 1});
				visited[x] = true;
			}
		}
	}
	return INT_MAX;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int ladders, snakes;
		cin >> ladders;
		unordered_set<int> ldr, snk;
		vector<int>* adj_list = new vector<int>[101]();
		for (int i = 0; i < ladders; i++) {
			int u, v;
			cin >> u >> v;
			for (int j = 1; j <= 6; j++) {
				if ((u - j) >= 0)
					adj_list[u - j].push_back(v);
			}
			ldr.insert(u);
		}
		cin >> snakes;
		for (int i = 0; i < snakes; i++) {
			int u, v;
			cin >> u >> v;
			for (int j = 1; j <= 6; j++) {
				if ((u - j) >= 1)
					adj_list[u - j].push_back(v);
			}
			snk.insert(u);
		}
		for (int i = 1; i <= 100; i++) {
			if (!ldr.count(i) && !snk.count(i)) {
				for (int j = 1; j <= 6; j++) {
					if ((i + j) <= 100) {
						adj_list[i].push_back(i + j);
					}
				}
			}
		}
		cout << bfs(adj_list) << endl;
		delete []adj_list;
	}
	return 0;
}
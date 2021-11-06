#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> *adj_list = new vector<int> [n + 1]();
	int useless = -1;
	cin >> useless;
	vector<int> input(n);
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj_list[x].push_back(i);
		adj_list[i].push_back(x);
	}
	queue<pii> q;
	unordered_set<int> directories;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int folder;
		cin >> folder;
		directories.insert(folder);
	}
	q.push({1, -1});
	int ans = 0;
	while (!q.empty()) {
		int vertex = q.front().first;
		int parent = q.front().second;
		q.pop();
		if (directories.count(vertex)) {
			ans++;
		}
		else {
			for (int x : adj_list[vertex]) {
				if (x != parent) {
					q.push({x, vertex});
				}
			}
		}
	}
	cout << ans << endl;
	delete []adj_list;
	return 0;
}
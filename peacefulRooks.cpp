#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int cycles;
vector<int> color;
bool cycleCheck(int v, vector<int> adj_list[]) {
	color[v] = 1;
	for (int x : adj_list[v]) {
		if (color[x] == 0) {
			if (cycleCheck(x, adj_list)) {
				return true;
			}
		} else if (color[x] == 1) {
			cycles++;
			return true;
		}
	}
	color[v] = 2;
	return false;
}
void solveQuestion() {
	int n, m;
	cin >> n >> m;
	cycles = 0;
	vector<int> adj_list[m];
	vector<pii> input;
	map<int, vector<int>> x_co;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u == v) {
			continue;
		}
		u--;
		v--;
		input.push_back({u, v});
		x_co[u].push_back(input.size() - 1);
	}
	int N = input.size();
	for (int i = 0; i < N; i++) {
		int y_co = input[i].second;
		for (int x : x_co[y_co]) {
			adj_list[i].push_back(x);
		}
	}
	// for (int i = 0; i < N; i++) {
	// 	cout << i << "->";
	// 	for (int x : adj_list[i]) {
	// 		cout << x << " ";
	// 	}
	// 	cout << '\n';
	// }
	color.assign(N, 0);
	for (int i = 0; i < N; i++) {
		if (color[i] == 0) {
			cycleCheck(i, adj_list);
		}
	}
	cout << N + cycles << '\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
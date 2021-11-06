#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { -1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool isSafe(int x, int y, int n) {
	return ((x >= 0) && (y >= 0) && (x < n) && (y < n));
}
int dijkstras(vector<vector<int>> &grid, int n) {
	set<pair<int, pair<int, int>>> s;
	vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
	s.insert({grid[0][0], {0, 0}});
	distance[0][0] = grid[0][0];
	while (!s.empty()) {
		auto min_vertex = *(s.begin());
		int dist = min_vertex.first;
		int x_co = (min_vertex.second).first;
		int y_co = (min_vertex.second).second;
		s.erase(s.begin());
		for (int i = 0; i < 4; i++) {
			if (isSafe(x_co + dx[i], y_co + dy[i], n)) {
				int neighbour_x = x_co + dx[i], neighbour_y = y_co + dy[i], curr_dist = distance[neighbour_x][neighbour_y];
				if (dist + grid[neighbour_x][neighbour_y] < curr_dist) {
					if (curr_dist != INT_MAX)
						s.erase({curr_dist, {neighbour_x, neighbour_y}});
					s.insert({dist + grid[neighbour_x][neighbour_y], {neighbour_x, neighbour_y}});
					distance[neighbour_x][neighbour_y] = dist + grid[neighbour_x][neighbour_y];
				}
			}
		}
	}
	return distance[n - 1][n - 1];
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}
		cout << dijkstras(grid, n) << "\n";
	}
	return 0;
}
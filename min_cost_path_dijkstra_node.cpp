#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { -1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool isSafe(int x, int y, int n) {
	return ((x >= 0) && (y >= 0) && (x < n) && (y < n));
}
struct node {
	int x_co, y_co, distance;
	node(int x_co, int y_co, int dist) {
		this->x_co = x_co;
		this->y_co = y_co;
		distance = dist;
	}
};
bool operator<(const node& a, const node& b)
{
	if (a.distance == b.distance)
	{
		if (a.x_co != b.x_co)
			return (a.x_co < b.x_co);
		else
			return (a.y_co < b.y_co);
	}
	return (a.distance < b.distance);
}
int dijkstras(vector<vector<int>> &grid, int n) {
	set<node> s;
	vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
	s.insert(node(0, 0, grid[0][0]));
	distance[0][0] = grid[0][0];
	while (!s.empty()) {
		node min_vertex = *(s.begin());
		int dist = min_vertex.distance;
		int x_cord = min_vertex.x_co;
		int y_cord = min_vertex.y_co;
		s.erase(node(x_cord, y_cord, dist));
		for (int i = 0; i < 4; i++) {
			if (isSafe(x_cord + dx[i], y_cord + dy[i], n)) {
				int neighbour_x = x_cord + dx[i], neighbour_y = y_cord + dy[i], curr_dist = distance[neighbour_x][neighbour_y];
				if (dist + grid[neighbour_x][neighbour_y] < curr_dist) {
					int new_dist = dist + grid[neighbour_x][neighbour_y];
					if (curr_dist != INT_MAX)
						s.erase(node(neighbour_x, neighbour_y, curr_dist));
					s.insert(node(neighbour_x, neighbour_y, new_dist));
					distance[neighbour_x][neighbour_y] = new_dist;
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
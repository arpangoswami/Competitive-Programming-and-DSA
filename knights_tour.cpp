#include <bits/stdc++.h>
#define N 5
using namespace std;
typedef long long ll;
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
void print(vector<vector<int>> &grid) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}
bool isSafe(vector<vector<int>> &grid, int x, int y) {
	return ((x >= 0) && (y >= 0) && (x < N) && (y < N) && grid[x][y] == -1);
}
bool knight(vector<vector<int>> &grid, int x, int y, int toPlace) {
	if (toPlace == N * N + 1) {
		return true;
	}
	for (int i = 0; i < 8; i++) {
		int x_co = x + dx[i], y_co = y + dy[i];
		if (isSafe(grid, x_co, y_co)) {
			grid[x_co][y_co] = toPlace;
			bool canSolve = knight(grid, x_co, y_co, toPlace + 1);
			if (canSolve) {
				return true;
			}
			grid[x_co][y_co] = -1;
		}
	}
	return false;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> grid(N, vector<int>(N, -1));
	int x, y;
	cin >> x >> y;
	grid[x - 1][y - 1] = 1;
	bool flag = knight(grid, x - 1, y - 1, 2);
	if (flag) {
		print(grid);
	} else {
		cout << "Solution doesn't exist" << "\n";
	}
	return 0;
}
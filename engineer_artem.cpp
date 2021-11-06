#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int dx[4] = { -1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
inline bool isSafe(int x, int y, int m, int n) {
	return ((x >= 0) && (y >= 0) && x < m && y < n);
}
void solveQuestion() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0) {
				if(arr[i][j]%2 == 1){
					arr[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 1) {
				if(arr[i][j]%2 == 0){
					arr[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void solveQuestion() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> arr(m, vector<int>(n));
	int neg = 0, sum = 0, minm = 101;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			sum += abs(arr[i][j]);
			if (arr[i][j] < 0) {
				neg++;
			}
			minm = min(minm, abs(arr[i][j]));
		}
	}
	if (neg % 2 == 0) {
		cout << sum << '\n';
		return;
	}
	cout << sum - 2 * minm << "\n";
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dp[101][101][101];
int LCStwist(string a, string b, int m, int n, int lengthRunning, int k) {
	if (m <= 0 || n <= 0) {
		if (lengthRunning >= k) {
			return lengthRunning;
		}
		return 0;
	}
	if (dp[m][n] >= 0) {
		return dp[m][n];
	}
	int ans;
	if (a[m - 1] == b[n - 1]) {
		int ans1 = LCStwist(a, b, m - 1, n - 1, 1 + lengthRunning, k);
		int ans2 = INT_MIN, ans3 = INT_MIN;
		if (lengthRunning >= k) {
			ans2 = lengthRunning + LCStwist(a, b, m - 1, n, 0, k);
			ans3 = lengthRunning + LCStwist(a, b, m, n - 1, 0, k);
		}
		else {
			ans2 = LCStwist(a, b, m - 1, n, 0, k);
			ans3 = LCStwist(a, b, m, n - 1, 0, k);
		}
		ans = max({ans1, ans2, ans3});
	} else {
		if (lengthRunning >= k) {
			ans = lengthRunning + max(LCStwist(a, b, m - 1, n, 0, k), LCStwist(a, b, m, n - 1, 0, k));
		}
		else {
			ans = max(LCStwist(a, b, m - 1, n, 0, k), LCStwist(a, b, m, n - 1, 0, k));
		}
	}
	return dp[m][n] = ans;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		string a, b;
		cin >> a >> b;
		int m = a.size(), n = b.size();
		memset(dp, -1, sizeof(dp));
		memset
		cout << LCStwist(a, b, m, n, 0, k) << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		ll** dp = new ll* [n];
		ll* sum = new ll[n + 1]();
		for (int i = 1; i <= n; ++i) {
			cin >> sum[i];
			sum[i] += sum[i - 1];
			dp[i - 1] = new ll[n]();
		}
		for (int i = 0; i < n; i++) {
			dp[i][i] = sum[i + 1] - sum[i];
		}
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i <= (n - len); i++) {
				int j = i + len - 1;
				ll sum_here = sum[i + len] - sum[i];
				dp[i][j] = max(sum_here - dp[i + 1][j], sum_here - dp[i][j - 1]);
			}
		}
		cout << dp[0][n - 1] << "\n";
		for (int i = 0; i < n; i++) {
			delete []dp[i];
		}
		delete []sum;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
const ll mod = 1e9 + 7;
ll solve(vector<int> &arr, int n, int m, vector<vector<ll>> &dp, int last) {
	if (n == 0) {
		return 1;
	}
	if (dp[n][last] != -1) {
		return dp[n][last];
	}
	if (arr[n - 1] != 0) {
		if (arr[n - 1] == last + 1 || arr[n - 1] == last - 1 || arr[n - 1] == last) {
			return dp[n][last] = solve(arr, n - 1, m, dp, arr[n - 1]);
		} else
			return dp[n][last] = 0;
	}
	ll ans = 0;
	if (last != 1) {
		ans += solve(arr, n - 1, m , dp, last - 1);
		ans %= mod;
	}
	ans += solve(arr, n - 1, m, dp, last);
	ans %= mod;
	if (last != m) {
		ans += solve(arr, n - 1, m, dp, last + 1);
		ans %= mod;
	}
	return dp[n][last] = ans;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	if (arr[n - 1] != 0) {
		ans = solve(arr, n - 1, m, dp, arr[n - 1]);
	} else {
		for (int i = 1; i <= m; i++) {
			ans += solve(arr, n - 1, m, dp, i);
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 1e15;
void solveQuestion() {
	int n, k;
	cin >> n >> k;
	vi arr(n + 1);
	vi prefix(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefix[i] = arr[i] + prefix[i - 1];
	}
	vector<int> dp[2];
	dp[0].resize(k + 1);
	dp[1].resize(k + 1);
	fill(dp[0].begin(), dp[0].end(), -INF);
	fill(dp[1].begin(), dp[1].end(), -INF);
	// dp[0].fill(-INF);
	// dp[1].fill(-INF);
	dp[0][0] = 0;
	dp[1][0] = 0;
	int ans = -INF;
	for (int i = 1; i <= n; i++) {
		vector<int> temp(k + 1, -INF);
		temp[0] = 0;
		for (int j = 1; j <= k; j++) {
			temp[j] = max(temp[j], dp[1][j - 1] + prefix[i] * j);
		}
		ans = max(ans, temp[k]);
		for (int j = 0; j <= k; j++) {
			int tt = max(dp[0][j], temp[j]) - prefix[i] * (j + 1);
			dp[1][j] = max(dp[1][j], tt);
			dp[0][j] = max(dp[0][j], temp[j]);
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
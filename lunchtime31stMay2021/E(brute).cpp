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
vector<int> parents;
int n;
int solve(int currState, vector<int> &dp) {
	if (dp[currState] != -1) {
		return dp[currState];
	}
	int &ans = dp[currState];
	ans = 0;
	for (int i = 1; i < n; i++) {
		int p = parents[i + 1] - 1;
		if ((currState >> p) & 1 == 0 && (currState >> i) & 1) {
			ans = max(ans, 1 + solve(((currState & (1 << i)) | (1 << p)), dp));
		}
	}
	return ans;
}
void solveQuestion() {
	cin >> n;
	string s;
	cin >> s;
	parents.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> parents[i];
	}
	int currState = 0;
	for (int i = 0; i < n; i++) {
		currState += 1 << (s[i] - '0');
	}
	vector<int> dp(1 << n, -1);
	cout << solve(currState, dp) << "\n";
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
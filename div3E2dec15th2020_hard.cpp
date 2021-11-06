#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int MOD = 1e9 + 7;
int sz = 2e5 + 5;
vector<int> fact(sz);
void pre() {
	fact[0] = 1;
	for (int i = 1; i < sz; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
}
int power(int x, int y) {
	int ans = 1LL;
	x %= MOD;
	while (y) {
		if (y & 1) {
			ans *= x;
			ans %= MOD;
		}
		x *= x;
		x %= MOD;
		y >>= 1;
	}
	return ans;
}
int ferm_inv(int n) {
	return power(n, MOD - 2);
}
int nCr(int x, int y) {
	if(x < 0 || y > x){
		return 0;
	}
	int val = fact[x];
	int div = fact[y] * fact[x - y];
	div %= MOD;
	return (val * ferm_inv(div)) % MOD;
}

void solveQuestion() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (m == 1) {
		cout << n << '\n';
		return;
	}
	if(m > n){
		cout<<0<<'\n';
		return;
	}
	int ans = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i <= (n - m); i++) {
		auto it = lower_bound(arr.begin() + i + (m - 1), arr.end(), arr[i] + k + 1);
		if (it != arr.begin())
			--it;
		int idx = it - arr.begin();
		int numBetween = idx - i;
		int add = nCr(numBetween, m - 1);
		ans += add;
		ans %= MOD;
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}

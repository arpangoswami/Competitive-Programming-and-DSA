#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[100005];
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		ll ans = 0;
		vector<int> arr(n);
		memset(pre, 0, sizeof(pre));
		pre[0] = 1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
			sum %= n;
			sum = (sum + n)%n;
			pre[sum]++;
		}
		for (int i = 0; i < n; i++) {
			ll val = pre[i];
			ans += (val * (val - 1)) / 2;
		}
		cout << ans << "\n";
	}
	return 0;
}
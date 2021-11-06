#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> teach(n);
	vector<int> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> teach[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> stu[i];
	}
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = teach[i] - stu[i];
	}
	sort(arr.begin(), arr.end());
	int idx = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		auto it = upper_bound(arr.begin() + i + 1, arr.end(), -val);
		ans += (arr.end() - it);
	}
	cout << ans << "\n";
	return 0;
}
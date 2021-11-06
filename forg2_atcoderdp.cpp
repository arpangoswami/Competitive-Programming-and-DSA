#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int in_size = min(n - 1, k);
	for (int i = 0; i <= in_size; i++) {
		dp[i] = abs(arr[i] - arr[0]);
	}
	for (int i = k + 1; i < n; i++) {
		int ans = INT_MAX;
		for (int j = 1; j <= k; j++) {
			ans = min(ans, dp[i - j] + abs(arr[i] - arr[i - j]));
		}
		dp[i] = ans;
	}
	cout << dp[n - 1] << "\n";
	return 0;
}
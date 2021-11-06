#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
bool func(int k,int n,int m,int val){
	int total = 0;
	for(int i=1;i<=n;i++){
		total+=min(m,(val-1)/i);
	}
	return total < k;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	int low = 1, high = n * m;
	int ans = 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (func(k, n, m, mid)) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
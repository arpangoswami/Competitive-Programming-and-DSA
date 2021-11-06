#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n,x;
		cin >> n >> x;
		int temp = x;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int idx1 = n;
		for(int i=0;i<n;i++){
			if(arr[i]>=temp){
				idx1 = i;
				break;
			}
		}
		int cnt = 0;
		for (int i = idx1; i < n; i++) {
			if (arr[i] > temp) {
				while (arr[i] > temp) {
					cnt++;
					temp *= 2;
				}
			}
			temp = arr[i] * 2;
			cnt++;
		}
		int ans1 = cnt + idx1;
		int ans2 = inf;
		temp = x;
		if (idx1 > 0 && arr[idx1] != x) {
			idx1--;
			cnt = 0;
			for (int i = idx1; i < n; i++) {
				if (arr[i] > temp) {
					while (arr[i] > temp) {
						cnt++;
						temp *= 2;
					}
				}
				cnt++;
				temp = arr[i] * 2;
			}
			ans2 = idx1 + cnt;
		}
		cout << min(ans1, ans2) << "\n";
	}
	return 0;
}

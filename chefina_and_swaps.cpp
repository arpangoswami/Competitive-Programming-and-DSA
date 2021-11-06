#include <bits/stdc++.h>
#define int long long
const int inf = 1e14;
using namespace std;
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> arr1(n);
		vector<int> arr2(n);
		unordered_map<int, int> total;
		unordered_map<int, int> firstArr;
		int ans = 0;
		bool exists = true;
		int minimum = inf;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
			firstArr[arr1[i]]++;
			total[arr1[i]]++;
			minimum = min(minimum, arr1[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
			total[arr2[i]]++;
			minimum = min(minimum, arr2[i]);
		}
		vector<int> extra;
		for (auto it = total.begin(); it != total.end() && exists; ++it) {
			int item = it->first;
			int frequency = it->second;
			if (frequency % 2 != 0) {
				exists = false;
			} else {
				if (frequency / 2 != firstArr[item]) {
					int diff = abs(frequency / 2 - firstArr[item]);
					for (int i = 0; i < diff; i++) {
						extra.push_back(item);
					}
				}
			}
		}
		sort(extra.begin(), extra.end());
		if (exists) {
			for (int i = 0; i < (int)extra.size()/2; i++) {
				ans += min(2*minimum,extra[i]);
			}
		}
		ans = exists ? ans : -1;
		cout << ans << "\n";
	}
	return 0;
}
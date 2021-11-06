#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ans = 0;
		ll maxi = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i-1]) {
				maxi = max(maxi,arr[i-1] - arr[i]);
				arr[i] = arr[i-1];
			}
		}
		cout<<(int)(ceil(log2(maxi+1)))<<"\n";
	}
	return 0;
}
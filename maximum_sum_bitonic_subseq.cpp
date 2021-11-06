#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> inc(n, 0);
		vector<int> dec(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		inc[0] = arr[0];
		dec[n - 1] = arr[n - 1];
		for (int i = 1; i < n; i++) {
			inc[i] = arr[i];
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i]) {
					inc[i] = max(inc[i], inc[j] + arr[i]);
				}
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			dec[i] = arr[i];
			for (int j = n - 1; j > i; j--) {
				if (arr[j] < arr[i]) {
					dec[i] = max(dec[i], dec[j] + arr[i]);
				}
			}
		}
		int maxm = 1;
		for (int i = 0; i < n; i++) {
			maxm = max(maxm, inc[i] + dec[i] - arr[i]);
		}
		cout << maxm << endl;
	}
	return 0;
}
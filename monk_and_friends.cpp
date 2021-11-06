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
		int n, m;
		cin >> n >> m;
		unordered_set<ll> s;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			s.insert(x);
		}
		for (int i = 0; i < m; i++) {
			ll x;
			cin >> x;
			if (s.count(x)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << endl;
			}
			s.insert(x);
		}
	}
	return 0;
}
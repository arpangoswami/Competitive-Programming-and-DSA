#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << endl;
	} else {
		ll idx = 0;
		for (ll i = 63; i >= 0; i--) {
			ll set1 = (a >> i) & 1;
			ll set2 = (b >> i) & 1;
			if (set1 != set2) {
				idx = i;
				break;
			}
		}
		ll ans = (1 << (idx + 1)) - 1;
		cout << ans << endl;
	}
	return 0;
}
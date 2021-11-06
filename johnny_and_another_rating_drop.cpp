#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		ll a;
		cin >> a;
		ll n = 0;
		for (ll i = 0; i <= 63; i++) {
			if ((1 << i) <= a) {
				n = i;
			} else {
				break;
			}
		}
		vector<ll> arr;
		for(ll i=0;i<=n;i++){
			arr.push_back(a/(1<<i));
		}
		for(ll i=0;i<n;i++){
			arr[i] = arr[i] - arr[i+1];
		}
		ll ans = 0;
		for(ll i=0;i<=n;i++){
			ans += (arr[i]*(1+i));
		}
		cout<<ans<<endl;
	}
	return 0;
}
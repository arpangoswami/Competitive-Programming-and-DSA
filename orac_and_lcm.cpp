#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<ll> suffix(n);
	suffix[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--){
		suffix[i] = __gcd(suffix[i+1],arr[i]);
	}
	ll ans = (arr[0]*suffix[1])/__gcd(arr[0],suffix[1]);
	for(int i=1;i<n-1;i++){
		ll temp = (arr[i]*suffix[i+1])/__gcd(arr[i],suffix[i+1]);
		ans = __gcd(ans,temp);
	}
	cout<<ans<<"\n";
	return 0;
}
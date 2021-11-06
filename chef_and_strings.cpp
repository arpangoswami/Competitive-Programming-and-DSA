#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<ll> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll ans = 0;
		for(int i=1;i<n;i++){
			ll from = arr[i-1];
			ll to = arr[i];
			ll maxm = max(from,to);
			ll minm = min(from,to);
			ans+=(maxm-minm-1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
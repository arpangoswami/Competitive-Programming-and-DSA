#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll smallestFactor(ll n){
	vector<ll> factors;
	if(n%2 == 0){
		return 2;
	}
	for(int i=3;i*i<=n;i+=2){
		if((n%i) == 0){
			return i;
		}
	}
	return n;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll n,k;
		cin>>n>>k;
		if(n%2 == 0){
			ll ans = n + 2*k;
			cout<<ans<<"\n";
		}
		else{
			ll sf = smallestFactor(n);
			n+=sf;
			ll ans = n + 2*(k-1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
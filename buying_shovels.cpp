#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll fact(ll n,ll k){
	if(n<=k){
		return n;
	}
	set<ll> factors;
	ll temp = n;
	for(int i=1;i*i<=n;i++){
		if(n%i == 0){
			factors.insert(i);
			factors.insert(n/i);
		}
	}
	ll ans = 1;
	for(ll x:factors){
		if(x<=k){
			ans = x;
		}
		else{
			break;
		}
	}
	return ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll n,k;
		cin>>n>>k;
		ll ans = fact(n,k);
		cout<<n/ans<<endl;
	}
	return 0;
}
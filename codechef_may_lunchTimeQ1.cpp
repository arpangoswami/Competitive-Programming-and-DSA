#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll power(ll a,ll b){
	if(b == 0){
		return 1;
	}
	ll smallAns = power(a,b/2);
	if(b&1){
		return smallAns*smallAns*a;
	}
	return smallAns*smallAns;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<ll> alice(n);
		vector<ll> bob(n);
		for(int i=0;i<n;i++){
			cin>>alice[i];
		}
		for(int i=0;i<n;i++){
			cin>>bob[i];
		}
		ll alice_dist = 0,bob_dist = 0,ans = 0;
		for(int i=0;i<n;i++){
			if(alice_dist == bob_dist){
				if(alice[i] == bob[i]){
					ans+=alice[i];
				}
			}
			alice_dist+=alice[i];
			bob_dist+=bob[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
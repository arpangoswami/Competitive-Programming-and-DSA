#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll fact(ll n,ll k){
	if(n<=k){
		return 1;
	}
	ll temp = n;
	map<ll,ll> mp;
	while(n%2 == 0){
		mp[2]++;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2){
		if(n%i == 0){
			mp[i]++;
			n/=i;
		}
	}
	if(n>2){
		mp[n]++;
		n = 1;
	}
	// for(auto it=mp.begin();it!=mp.end();++it){
	// 	cout<<it->first<<"->"<<it->second<<endl;
	// }
	ll to_divide = 1,ans = temp;
	while(to_divide<=k){
		auto it = mp.begin();
		if(to_divide * it->first<=k){
			to_divide*=it->first;
			ans/=it->first;
			mp[it->first]--;
			if(mp[it->first] == 0){
				mp.erase(it->first);
			}
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
		cout<<ans<<endl;
	}
	return 0;
}
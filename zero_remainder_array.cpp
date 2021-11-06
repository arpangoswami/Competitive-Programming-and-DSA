#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll n,k;
		cin>>n>>k;
		vector<ll> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		bool flag = true;
		for(int i=0;i<n;i++){
			if(arr[i] % k!=0){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<0<<"\n";
		}else{
			map<ll,int> bucket;
			for(int i=0;i<n;i++){
				ll rem = arr[i] % k;
				bucket[rem]++;
			}
			ll maximum = 0,maxIdx = 0;
			for(auto it = bucket.rbegin();it!=bucket.rend();++it){
				ll val = it->second;
				ll rem = it->first;
				if(val>=maximum && rem!=0){
					maximum = val;
					maxIdx = rem;
				}
			}
			ll extra = k - maxIdx;
			ll ans = k*(maximum - 1);
			ans+=extra;
			ans++;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
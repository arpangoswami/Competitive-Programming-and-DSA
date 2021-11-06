#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mp[arr[i]] = -1;
		}
		if(mp.size() < k){
			cout<<n<<"\n";
			continue;
		}
		set<pii> st;
		for(auto x:mp){
			st.insert({x.second,x.first});
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			st.erase({mp[arr[i]],arr[i]});
			mp[arr[i]] = i;
			st.insert({mp[arr[i]],arr[i]});
			ans = max(ans,i-(*st.begin()).first);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
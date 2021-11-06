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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		unordered_map<int,int> mp;
		int pref = 0;
		mp[pref]++;
		//count subarrays of sum 0
		for(int i=0;i<n;i++){
			pref+=(s[i] - '0' - 1);
			ans += mp[pref];
			mp[pref]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
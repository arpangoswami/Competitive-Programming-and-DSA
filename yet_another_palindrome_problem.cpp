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
		cin>>n;
		vector<int> arr(n);
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mp[arr[i]]++;
		}
		bool flag = false;
		mp[arr[0]]--;
		for(int i=1;i<(n-1) && !flag;i++){
			mp[arr[i]]--;
			for(int j=0;j<i && !flag;j++){
				if(mp[arr[j]]){
					flag = true;
				}
			}
		}
		string ans = flag ? "YES" : "NO";
		cout<<ans<<"\n";
	}
	return 0;
}
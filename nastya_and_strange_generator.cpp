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
		int idx = -1;
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mp[arr[i]] = i;
		}
		int need = 1;
		unordered_set<int> st;
		bool flag = true;
		while(need <= n && flag){
			idx = mp[need];
			st.insert(need);
			need++;
			for(int i=idx+1;i<n;i++){
				if(st.count(arr[i])){
					break;
				}
				if(arr[i]!=need){
					flag = false;
					break;
				}
				st.insert(need);
				need++;
			}
		}
		string ans = flag ? "Yes":"No";
		cout<<ans<<"\n";
	}
	return 0;
}
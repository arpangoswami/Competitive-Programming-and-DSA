#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int minCost(vector<int> &arr,int idx){
	unordered_map<int,int> mp;
	for(int i=idx;i<arr.size();i++){
		mp[arr[i]]++;
	}
	int fights = 0;
	for(auto it:mp){
		if(it.second > 1){
			fights += it.second;
		}
	}
	return fights;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin >> n >> k;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		int ans = minCost(arr,0) + k;
		for(int i=2;i<=n;i++){
			int ct = i*k;
			if(ct >= ans){
				break;
			}
			unordered_set<int> st;
			int cnt = 1;
			int other = 0;
			int idx = -1;
			for(int j=0;j<n;j++){
				if(st.count(arr[j])){
					cnt++;
					st.clear();
				}
				if(cnt == i){
					idx = j;
					break;
				}
				st.insert(arr[j]);
			}
			if(idx!=-1){
				other = minCost(arr,idx);
			}
			ans = min(ans,other + i*k);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
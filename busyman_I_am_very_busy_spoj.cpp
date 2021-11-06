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
		array<int,2> arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i][1]>>arr[i][0];
		}
		sort(arr,arr+n);
		set<array<int,2>>dp;
		int max_activities = 0;
		dp.insert({-1,0});
		for(int i=0;i<n;i++){
			auto it = dp.lower_bound({arr[i][1],n+1});
			--it;
			int done = (*it)[1];
			max_activities = max(max_activities,done + 1);
			dp.insert({arr[i][0],max_activities});
		}
		cout<<max_activities<<"\n";
	}
	return 0;
}
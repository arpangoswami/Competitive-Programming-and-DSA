#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
array<int,3> arr[mx];
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i][1]>>arr[i][0]>>arr[i][2];
	}
	sort(arr,arr+n);
	set<array<ll,2>>dp;
	dp.insert({0,0});
	ll max_pf = 0;
	for(int i=0;i<n;i++){
		auto it = dp.lower_bound({arr[i][1]});
		--it;
		max_pf = max(max_pf,(*it)[1] + arr[i][2]);
		dp.insert({arr[i][0],max_pf});
	}
	cout<<max_pf<<"\n";
	return 0;
}
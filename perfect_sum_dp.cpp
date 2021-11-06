#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9 + 7;
ll numberOfSubsets(vector<int> &arr,int i,const int n,const int sum,int tillNow,ll **dp){
	if(dp[i][tillNow]!=-1){
		return dp[i][tillNow];
	}
	if(i == n){
		if(sum == tillNow){
			return 1;
		}
		return 0;
	}
	else if(sum<tillNow){
		return 0;
	}
	ll ans1 = numberOfSubsets(arr,i+1,n,sum,tillNow+arr[i],dp);
	ll ans2 = numberOfSubsets(arr,i+1,n,sum,tillNow,dp);
	return dp[i][tillNow] = (ans1+ans2)%mod;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		ll s = 0;
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			s+=arr[i];
		}
		ll **dp = new ll* [n+1];
		for(int i=0;i<=n;++i){
			dp[i] = new ll[s+1];
			for(int j=0;j<=s;++j){
				dp[i][j] = -1;
			}
		}
		int sum;
		cin>>sum;
		cout<<numberOfSubsets(arr,0,n,sum,0,dp)<<endl;
		for(int i=0;i<=n;++i){
			delete []dp[i];
		}
		delete []dp;
	}
	return 0;
}
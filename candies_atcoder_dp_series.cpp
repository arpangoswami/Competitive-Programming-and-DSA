#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
ll countCandy(int idx,int candies,int n,vector<int> &arr,vector<vector<ll>> &dp){
	if(idx == n){
		if(candies == 0){
			return 1;
		}
		return 0;
	}
	if(dp[idx][candies]!=-1){
		return dp[idx][candies];
	}
	ll ans = 0;
	for(int i=0;i<=arr[idx] && i<=candies;i++){
		ans+=countCandy(idx+1,candies-i,n,arr,dp);
		ans%=mod;
	}
	return dp[idx][candies] = ans;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
	for(int i=0;i<=arr[0] && i<=k;i++){
		ans += countCandy(1,k-i,n,arr,dp);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
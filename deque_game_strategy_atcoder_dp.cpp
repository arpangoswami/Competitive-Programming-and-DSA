#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll optimalGame(vector<ll> &arr,int i,int j,vector<ll> &prefixSum,vector<vector<ll>> &dp){
	if(i == j){
		return arr[i];
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll ans = max((arr[i]+(prefixSum[j]-prefixSum[i]-optimalGame(arr,i+1,j,prefixSum,dp))),(arr[j]+(prefixSum[j-1]-prefixSum[i-1]-optimalGame(arr,i,j-1,prefixSum,dp))));
	return dp[i][j] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> arr(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	vector<ll> prefixSum(n+1,0);
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
	prefixSum[1] = arr[1];
	for(int i=2;i<=n;i++){
		prefixSum[i] = prefixSum[i-1] + arr[i];
	}
	ll taro = optimalGame(arr,1,n,prefixSum,dp);
	ll jiro = prefixSum[n] - taro;
	cout<<taro - jiro<<endl;
	return 0;
}
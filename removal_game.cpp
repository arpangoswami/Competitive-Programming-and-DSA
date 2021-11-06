#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
ll dp[5005][5005];
ll solve(int i,int j,vector<ll> &arr){
	if(i > j){
		return 0;
	}
	if(i == j){
		return arr[i];
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll ans1 = arr[i] + min(solve(i+2,j,arr),solve(i+1,j-1,arr));
	ll ans2 = arr[j] + min(solve(i+1,j-1,arr),solve(i,j-2,arr));
	return dp[i][j] = max(ans1,ans2);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,n-1,arr);
	return 0;
}
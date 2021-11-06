#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int solve(vector<int> &arr,int sum,int idx,vector<vector<int>> &dp){
	if(sum == 0){
		return 1;
	}
	if(sum < 0 || idx == arr.size()){
		return 0;
	}
	
	if(dp[sum][idx]!=-1){
		return dp[sum][idx];
	}
	dp[sum][idx] = 0;
	return dp[sum][idx] = solve(arr,sum-arr[idx],idx+1,dp) || solve(arr,sum,idx+1,dp);
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int s = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		s+= arr[i];
	}
	if(s % 2 != 0){
		cout<<"NO"<<"\n";
		return;
	}
	vector<vector<int>> dp(s/2 + 1,vector<int>(n + 1,-1));
	sort(arr.begin(),arr.end(),greater<int>());
	int ans = solve(arr,s/2,0,dp);
	if(ans){
		cout<<"YES"<<"\n";
	}else{
		cout<<"NO"<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
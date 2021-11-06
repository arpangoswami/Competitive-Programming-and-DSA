#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int dp[205][515];
int solve(int n,int val,vector<int> &arr1,vector<int> &arr2){
	if(n == 0){
		return val;
	}
	if(dp[n][val]!=-1){
		return dp[n][val];
	}
	int ans = 600;
	for(int j=0;j<arr2.size();j++){
		int temp = val | (arr1[n-1] & arr2[j]);
		ans = min(ans,temp | solve(n-1,temp,arr1,arr2));
	}
	return dp[n][val] = ans;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> arr1(n);
	vector<int> arr2(m);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	memset(dp,-1,sizeof(dp));
	int ans = solve(n,0,arr1,arr2);
	cout << ans << "\n";
	return 0;
}
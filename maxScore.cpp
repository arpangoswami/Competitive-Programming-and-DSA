#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[1001][10001][2];
vector<array<int,2>> arr;
int n,k;
const int inf = 1e13;
int solve(int i,int time,int forget){
	if(i == n){
		if(forget){
			return 0;
		}
		return -inf;
	}
	if(dp[i][time][forget] != -1){
		return dp[i][time][forget];
	}
	int &ans = dp[i][time][forget];
	ans = solve(i+1,time,forget);
	if(forget == 1){
		if(time >= arr[i][1]){
			ans = max(ans,arr[i][0] + solve(i+1,time - arr[i][1],forget));
		}
	}else{
		if(time >= arr[i][1]){
			ans = max({ans,arr[i][0] + solve(i+1,time-arr[i][1],forget),solve(i+1,time-arr[i][1],1)});
		}
	}
	return ans;
}
void solveQuestion(){
	cin >> n >> k;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int l=0;l<=1;l++){
				dp[i][j][l] = -1;
			}
		}
	}
	int ans = max(0LL,solve(0,k,0));
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
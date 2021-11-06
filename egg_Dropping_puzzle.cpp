#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[51][11];
int solve(int floors,int eggs){
	if(eggs == 1){
		return floors;
	}
	if(floors == 0){
		return 0;
	}
	if(dp[floors][eggs]!=-1){
		return dp[floors][eggs];
	}
	int &ans = dp[floors][eggs];
	ans = floors;
	for(int i=1;i<=floors;i++){
		ans = min(ans,1 + max(solve(i-1,eggs-1),solve(floors-i,eggs)));
	}
	return ans;
}
void solveQuestion(){
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin >> n >> k;
	cout<<solve(k,n)<<"\n";
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
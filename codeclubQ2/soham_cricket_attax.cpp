#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int dp[301][301][51][2];
int n1,n2,k1,k2;
int solve(int batsman,int bowler,int consecutive,int lastPicked){
	if(batsman == 0 && bowler == 0){
		return 1LL;
	}
	int &ans = dp[batsman][bowler][consecutive][lastPicked];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	if(lastPicked == 0){
		if(batsman == 0 || consecutive == k1){
			//has to place a bowler here
			if(bowler == 0){
				ans = 0;
			}else{
				ans = solve(batsman,bowler-1,1,1);
			}	
		}else{
			//can place a batsman here
			ans = solve(batsman-1,bowler,consecutive+1,0);
			//if possible can also place a bowler here
			if(bowler > 0){
				ans += solve(batsman,bowler-1,1,1);
				ans %= MOD;
			}
		}
	}
	else{
		if(bowler == 0 || consecutive == k2){
			//has to place a batsman here
			if(batsman == 0){
				ans = 0;
			}else{
				ans = solve(batsman-1,bowler,1,0);
			}
		}else{
			//places a bowler here
			ans = solve(batsman,bowler-1,consecutive+1,1);
			//if possible also places a batsman
			if(batsman > 0){
				ans += solve(batsman-1,bowler,1,0);
				ans %= MOD;
			}
		}
	}
	return ans;
	
}
void solveQuestion(){
	cin >> n1 >> n2 >> k1 >> k2;
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			int maxL = max(k1,k2);
			for(int k=0;k<=maxL;k++){
				dp[i][j][k][0] = -1;
				dp[i][j][k][1] = -1;
			}
		}
	}
	cout << (solve(n1-1,n2,1,0) + solve(n1,n2-1,1,1)) % MOD;
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	#ifndef ONLINE_JUDGE

	freopen("tc10.txt", "r", stdin);

	freopen("output10.txt", "w", stdout);

	#endif // ONLINE_JUDGE
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
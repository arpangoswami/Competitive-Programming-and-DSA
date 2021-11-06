#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1000000007LL;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int n;
vi pref;
int dp[201][201][61];
int solve(int startWindow,int currInd,int rankWindow){
	if(currInd == n){
		int x = pref[currInd] ^ pref[startWindow-1];
		if((x % (1LL<<rankWindow)) == 0){
			return 1;
		}
		return 0;
	}
	int &ans = dp[startWindow][currInd][rankWindow];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	int x = pref[currInd] ^ pref[startWindow-1];
	if((x % (1LL<<rankWindow)) == 0){
		ans += solve(currInd+1,currInd+1,rankWindow+1);
		ans %= MOD;
	}
	ans += solve(startWindow,currInd+1,rankWindow);
	ans %= MOD;
	return ans;
}
void solveQuestion(){
	cin >> n;
	pref.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> pref[i];
		pref[i] ^= pref[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=60;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	cout << solve(1,1,0) << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
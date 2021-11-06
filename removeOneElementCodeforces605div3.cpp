#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vector<vector<int>> dp(2,vector<int>(n+1,1));
	dp[0][0] = 0;
	dp[1][0] = 0;
	int ans = 1;
	for(int i=1;i<=n;i++){
		if(arr[i] > arr[i-1]){
			dp[0][i] = 1 + dp[0][i-1];
			dp[1][i] = 1 + dp[1][i-1];
		}
		if(i >= 2 && arr[i] > arr[i-2])
			dp[1][i] = max(dp[1][i],1 + dp[0][i-2]);
		ans = max({ans,dp[0][i],dp[1][i]});
	}
	cout<<ans;
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
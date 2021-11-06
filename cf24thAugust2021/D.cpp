#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
void solveQuestion(){
	int N,MOD;
	cin >> N >> MOD;
	vector<int> dp(N+1);
	vector<int> pref(MOD+1);
	dp[1] = 1;
	pref[1] = 1;
	for(int i=2;i<=N;i++){
		dp[i] = pref[i-1];
		for(int j=2;j*j+j<=i;j++){
			dp[i] += dp[(i/j)];
			dp[i] %= MOD;
		}
		for(int res=1;res*res<=i;res++){
			int left = (i/(res+1)) + 1,right = i/res;
			dp[i] += (right-left+1)*dp[res];
			dp[i] %= MOD;
		}
		pref[i] = (pref[i-1] + dp[i])%MOD;
		pref[i] %= MOD;
	}
	cout << dp[N] << "\n";
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
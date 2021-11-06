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
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
const int MX = 2e5;
int n,k;
vector<int> arr;
int dp[10001][501][3][2];
int solve(int requiredSum,int idx,int cons,int pick){
	if(idx >= n || cons >= 2){
		if(requiredSum == 0){
			return 0;
		}
		return 1e9;
	}
	int &ans = dp[requiredSum][idx][cons][pick];
	if(ans != -1){
		return ans;
	}
	//have to skip
	if(requiredSum < arr[idx]){
		return ans = solve(requiredSum,idx+1,cons+pick,0);
	}
	//skip or pick
	return ans = min(solve(requiredSum,idx+1,cons+pick,0),1 + solve(requiredSum-arr[idx],idx+1,cons,1));
}
void solveQuestion(){
	cin >> n >> k;
	arr.clear();
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<=n;j++){
			for(int m=0;m<=2;m++){
				dp[i][j][m][0] = -1;
				dp[i][j][m][1] = -1;
			}
		}
	}
	int ans = solve(k,0,0,0);
	ans = (ans > n) ? -1 : ans;
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}
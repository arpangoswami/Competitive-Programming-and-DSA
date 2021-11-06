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
vi arr;
vi pref;
int n;
int dp[301][301][301];
int calSum(int i,int j){
	return pref[j] - ((i > 0) ? pref[i-1] : 0);
}
int solve(int leftMost,int i,int grp){
	if(i >= n){
		if(leftMost >= n){
			return 1;
		}
		return 0;
	}
	int &ans = dp[leftMost][i][grp];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	int sum = calSum(leftMost,i);
	if(sum % grp == 0){
		ans += solve(i+1,i+1,grp+1);
		ans += solve(leftMost,i+1,grp);
		ans %= MOD;
	}else{
		ans += solve(leftMost,i+1,grp);
	}
	return ans;
}
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	for(int &i:arr){
		cin >> i; 
	}
	pref.resize(n);
	pref[0] = arr[0];
	for(int i=1;i<n;i++){
		pref[i] = pref[i-1] + arr[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	int ans = solve(0,0,1);
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
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
int evenOnesSum;
vector<int> dp;
int n;
int recDp(int i){
	if(i == 0){
		return dp[0] = 1;
	}
	if(dp[i] != -1){
		return dp[i];
	}
	int &ans = dp[i];
 
	//Fill all ones at ith bit
	if(n % 2 == 0){
		//1 placed at MSB position AND will have 1 XOR will have 0
 
		//Remaining positions n*(i-1) can put 0 or 1 anything
		ans = power(2,n*(i-1));
	}else{
		//Both AND, XOR will have 1 here
		ans = recDp(i-1);
	}
	//Fill even number of ones here
	//nC0 + nC2 + ... = power(2,n-1);
	//Subtract one if n even as already considered above
	ans += ((power(2LL,n-1) - n % 2 == 0)%MOD * recDp(i-1))% MOD;
	ans %= MOD;
	return ans;
}
void solveQuestion(){
	int k;
	cin >> n >> k;
	dp.resize(k+1,-1);
	fill(dp.begin(),dp.end(),-1);
	cout << recDp(k) << "\n";
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
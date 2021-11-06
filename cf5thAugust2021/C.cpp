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
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
string s;
int N;
int dp[11][2][2];
vector<int> mp(19);
int solve(int idx,int carry1,int carry2){
	if(idx == 0){
		int num = s[idx] - '0' - carry1;
		if(num < 0 || carry2){
			return 0;
		}
		return mp[num];
	}
	if(dp[idx][carry1][carry2] != -1){
		return dp[idx][carry1][carry2];
	}
	int &ans = dp[idx][carry1][carry2];
	int num = s[idx] - '0' - carry1;
	ans = 0;
	if(num >= 0){
		ans += mp[num] * solve(idx-1,carry2,0);
	}
	if(num <= 8){
		ans += mp[num+10] * solve(idx-1,carry2,1);
	}
	return ans;
}
void solveQuestion(){
	cin >> s;
	N = s.size();
	for(int i=0;i<=N;i++){
		dp[i][0][0] = -1;
		dp[i][0][1] = -1;
		dp[i][1][0] = -1;
		dp[i][1][1] = -1;
	}
	int ans = solve(N-1,0,0);
	cout << ans - 2 << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	for(int i=0;i<=18;i++){
		mp[i] = 10 - abs(9-i);
	}
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
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
vector<int> primes;
vector<int> LCM;
void LCMfunc(int n)
{
	LCM.push_back(1);
	for(int i=2;i<=n;i++){
		int lcm = (LCM.back() * i)/gcd(LCM.back(),i);
		LCM.push_back(lcm);
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	int N = LCM.size();
	int ans = 0;
	for(int i=1;i<N;i++){
		int wt = (i+1);
		int times = (n/LCM[i-1]) - (n/LCM[i]);
		ans += (wt * (times%MOD))%MOD;
	}
	cout<<ans%MOD<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	LCMfunc(42);
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
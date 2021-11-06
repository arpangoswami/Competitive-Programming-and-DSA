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
const int MOD = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
const int MX = 2e5;
vector<int> fact(MX+1);
void pre(){
	fact[0] = 1;
	for(int i=1;i<=MX;i++){
		fact[i] = (fact[i-1] * i)%MOD;
	}
}
int nCr(int N,int r){
	if(r > N || r < 0 || N < 0){
		return 1;
	}
	int num = fact[N];
	int den = fermat_inv((fact[r]*fact[N-r])%MOD);
	return (num*den)%MOD;
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	if((arr[n-1] - arr[n-2]) >= 2){
		cout<<"0\n";
		return;
	}
	if(arr[n-1] == arr[n-2]){
		cout<<fact[n]<<"\n";
		return;
	}
	int cnt = 0;
	int sMax = arr[n-2];
	for(int x:arr){
		if(x == sMax){
			cnt++;
		}
	}
	int ans = 0;
	for(int i=0;i<(n-1);i++){
		if(i < cnt){
			ans += fact[n-1];
			ans %= MOD;
		}else{
			int rem = (n-cnt-1);
			int pl = (i-cnt);
			int sub = ((nCr(rem,pl)*fact[i])%MOD*fact[n-1-i])%MOD;
			ans += (fact[n-1] - sub + MOD)%MOD;
			ans %= MOD;
		}
	}
	cout << ans%MOD << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
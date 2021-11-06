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
	int c1,c2,c3;
	cin >> c1 >> c2 >> c3;
	int a1,a2,a3,a4,a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	if(c1 < a1 || c2 < a2 || c3 < a3){
		cout<<"NO\n";
		return;
	}
	c1 -= a1;
	c2 -= a2;
	c3 -= a3;
	int sub = min(a4,c1);
	c1 -= sub;
	a4 -= sub;
	sub = min(a5,c2);
	c2 -= sub;
	a5 -= sub;
	if(c3 < a4 + a5){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
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
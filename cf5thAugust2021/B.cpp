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
const int MX = 3e5;
int XOR[MX+1];
void pre(){
	XOR[0] = 0;
	for(int i=1;i<=MX;i++){
		XOR[i] = XOR[i-1] ^ i;
	}
}
void solveQuestion(){
	int a,b;
	cin >> a >> b;
	int xorTill = XOR[a-1];
	if(xorTill == b){
		cout<<a<<"\n";
	}else if((xorTill ^ a) == b){
		cout << a + 2 << '\n';
	}else{
		cout << a + 1 << "\n";
	}
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
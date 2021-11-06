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
	int a,b,x,y,n;
	cin >> a >> b >> x >> y >> n;
	int ans = a*b;
	int tA = a,tB = b;
	tA = max(x,a-n);
	if((a-tA) < n){
		int diff = n-a+tA;
		tB = max(b-diff,y);
	}
	ans = min(ans,tA*tB);
	//cout<<"tA: "<<tA<<" tB: "<<tB<<"\n";
	tA = a,tB = b;
	tB = max(y,b-n);
	if((b-tB) < n){
		int diff = n - b + tB;
		tA = max(a-diff,x);
	}
	ans = min(ans,tA*tB);
	cout<<ans<<"\n";
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
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
	int r,c,k;
	cin >> r >> c >> k;
	int r1,r2,c1,c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int length = r2-r1+1,breadth = c2-c1+1;
	int ans = 2*(length+breadth);
	if(r2 == r){
		ans -= breadth;
	}
	if(r1 == 1){
		ans -= breadth;
	}
	if(c2 == c){
		ans -= length;
	}
	if(c1 == 1){
		ans -= length;
	}
	ans += min({c1-1,r1-1,r-r2,c-c2});
	ans += (length-1)*breadth + (breadth-1)*length;
	cout<<ans<<endl;
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
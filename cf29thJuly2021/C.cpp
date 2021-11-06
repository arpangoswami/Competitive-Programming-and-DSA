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
	int n,m;
	cin >> n >> m;
	//Find smallest x such that n ^ x > m
	int ans = 1e10,build = 0;
	for(int i=30LL;i>=0LL;i--){
		int bt1 = (n >> i) & 1, bt2 = (m >> i)&1;
		if(bt2 == 1){
			if(bt1 == 1){
				//do nothing
			}else{
				//keep up with m
				build += (1LL << i);
			}
		}else if(bt2 == 0){
			if(bt1 == 1){
				// chance to go ahead by doing nothing
				ans = min(ans,build);
			}else{
				// chance to go ahead by adding up
				ans = min(ans,build + (1LL << i));
			}
		}
	}
	cout << ans << "\n";
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
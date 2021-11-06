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
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	if(k == 0){
		cout<<"YES\n";
		cout<<"0\n";
		return;
	}
	if(k % 2 == 0){
		cout<<"NO\n";
		return;
	}
	int sz = 0;
	for(int i=0;i<=30;i++){
		if((k >> i) & 1){
			sz = i;
		}
	}
	sz++;
	k += ((1 << sz) - 1);
	k /= 2LL;
	cout<<"YES\n";
	cout<<sz<<"\n";
	vector<int> steps;
	int ans = 1;
	for(int i=sz-2;i>=0;i--){
		if((k >> i) & 1){
			steps.push_back(ans);
			ans += (1 << i);
		}else{
			ans -= (1 << i);
			steps.push_back(ans);
		}
	}
	for(int i=sz-2;i>=0;i--){
		cout<<steps[i]<<"\n";
	}
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
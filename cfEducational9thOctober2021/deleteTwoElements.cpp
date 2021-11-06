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
	int n;
	cin >> n;
	vi arr(n);
	int sum = 0LL;
	map<int,int> mp;
	for(int &i:arr){
		cin >> i;
		sum += i;
		mp[i]++;
	}
	int ans = 0LL;
	double mean = (sum/(n*1.0));
	for(int x:arr){
		double diff = mean - x;
		double req = mean + diff;
		mp[x]--;
		if(mp[x] == 0){
			mp.erase(x);
		}
		if(req == (int)req && mp.count((int)req)){
			ans += mp[req];
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
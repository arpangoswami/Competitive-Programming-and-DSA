#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ldb long double
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
	int n;
	cin >> n;
	vector<int> arr(n);
	int s2 = 0,s1 = INT_MIN;
	for(int &x:arr){
		cin >> x;
		s2 += x;
		s1 = max(x,s1);
	}
	s2 -= s1;
	double mx = (s2 * 1.0)/(n-1);
	cout << fixed << setprecision(12) << s1 + mx << "\n";
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
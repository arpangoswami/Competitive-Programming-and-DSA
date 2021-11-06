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
int power(int a, int b){int res=1;a=a;while(b>0){if(b&1){res=(res*a);}a=(a*a);b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	k++;
	int ans = 0;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
	}
	for(int i=0;i<n && k > 0;i++){
		if(i == n-1){
			ans += k*power(10LL,arr[i]);
		}else{
			int add = min(k,power(10LL,arr[i+1]-arr[i]) - 1);
			k -= add;
			ans += add * power(10LL,arr[i]);
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
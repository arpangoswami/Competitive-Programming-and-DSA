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
const int inf = 1e9;
const int MX = 2e5;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> leftClosest(n);
	vector<int> rightClosest(n);
	leftClosest[0] = (s[0] == '1') ? 0 : -inf;
	rightClosest[n-1] = (s[n-1] == '1') ? n-1: inf;
	for(int i=1;i<n;i++){
		leftClosest[i] = leftClosest[i-1];
		if(s[i] == '1'){
			leftClosest[i] = i;
		}
	}
	for(int i=n-2;i>=0;i--){
		rightClosest[i] = rightClosest[i+1];
		if(s[i] == '1'){
			rightClosest[i] = i;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		int dist = min(i-leftClosest[i],rightClosest[i]-i);
		ans += dist;
	}
	cout << ans << "\n";
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
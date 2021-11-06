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
	int n;
	cin >> n;
	vi arr(n);
	vi copy(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		copy[i] = arr[i];
	}
	sort(copy.begin(),copy.end());
	vi pref(n);
	pref[0] = copy[0];
	for(int i=1;i<n;i++){
		pref[i] = pref[i-1] + copy[i];
	}
	int ans = 0;
	for(int i=1;i<n;i++){
		int idx = lower_bound(copy.begin(),copy.end(),arr[i]) - copy.begin();
		if(idx > 0){
			int neg = pref[idx-1] - (arr[i] * idx);
			ans += neg;
		}
	}
	ans += copy[n-1];
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
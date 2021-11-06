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
	int n,k;
	cin >> n >> k;
	vi arr(n);
	vi useless(n);
	for(int &i:arr){
		cin >> i;
	}
	for(int &i:useless){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	vector<int> pref(n);
	vector<int> suff(n);
	for(int i=0;i<n;i++){
		int lIdx = lower_bound(arr.begin(),arr.end(),arr[i]-k) - arr.begin();
		pref[i] = i-lIdx+1;
		int rIdx = upper_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin()-1;
		suff[i] = rIdx-i+1;
	}
	for(int i=1;i<n;i++){
		pref[i] = max(pref[i],pref[i-1]);
	}
	for(int i=n-2;i>=0;i--){
		suff[i] = max(suff[i],suff[i+1]);
	}
	int ans = 1;
	for(int i=0;i<(n-1);i++){
		ans = max(ans,pref[i]+suff[i+1]);
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
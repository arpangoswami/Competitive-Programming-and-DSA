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
	int n,q;
	cin >> n >> q;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	vector<int> pref(n);
	pref[0] = arr[0] - 1;
	for(int i=1;i<n;i++){
		pref[i] = pref[i-1] + (arr[i] - arr[i-1] - 1);
	}
	for(int i=0;i<q;i++){
		int x;
		cin >> x;
		if(x <= pref[0]){
			cout<<x<<"\n";
		}else if(x > pref[n-1]){
			cout<<arr[n-1] + (x-pref[n-1])<<"\n";
		}else{
			int idx = lower_bound(pref.begin(),pref.end(),x) - pref.begin() - 1;
			int diff = x - pref[idx];
			cout<<arr[idx] + diff<<"\n";
		}
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
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
const int MX = 2e5;
typedef priority_queue<int,vector<int>,greater<int>> minHeap;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vector<int> pref(n+1);
	for(int i=1;i<=n;i++){
		pref[i] = pref[i-1] + arr[i];
	}
	auto calSum = [&](int l,int r){
		return (pref[r] - pref[l-1]);
	};
	int ans = (n+1);
	for(int i=1;i<=n;i++){
		int firstCnt = (n+1),secCnt = (n+1);
		ans = min(ans,firstCnt + secCnt);
	}
	ans = (ans > n) ? -1 : ans;
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
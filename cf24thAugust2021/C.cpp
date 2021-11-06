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
bool check(int minPower,vector<pii> &powers,int n){
	for(int i=0;i<n;i++){
		if(minPower < powers[i].ff){
			return false;
		}
		minPower += powers[i].ss;
	}
	return true;
}
int minPowerReq(vector<int> &cave,int n){
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans,cave[i] + 1 - i);
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<vector<int>> caves(n);
	for(int i=0;i<n;i++){
		int sz;
		cin >> sz;
		caves[i].resize(sz);
		for(int &x:caves[i]){
			cin >> x;
		}
	}
	vpi powers(n);
	for(int i=0;i<n;i++){
		powers[i] = {minPowerReq(caves[i],caves[i].size()),caves[i].size()};
	}
	sort(powers.begin(),powers.end(),[](auto &p1,auto &p2){
		if(p1.ff == p2.ff){
			return p1.ss > p2.ss;
		}
		return p1.ff < p2.ff;
	});
	int low = powers[0].ff,high = powers[n-1].ff,ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,powers,n)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
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
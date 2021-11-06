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
	vector<int> startDays(n);
	vector<int> duration(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> startDays[i] >> duration[i];
		mp[startDays[i]]++;
		mp[startDays[i]+duration[i]]--;
	}
	int currSum = 0;
	map<int,int> prefAdd;
	for(auto it:mp){
		currSum += it.second;
		prefAdd[it.first] = currSum;
	}
	vector<int> ans(n+1);
	for(auto it:prefAdd){
		auto it2 = prefAdd.upper_bound(it.first);
		if(it2 != prefAdd.end()){
			int v = it2->first;
			ans[it.second] += (v-it.first);
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout<<"\n";
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
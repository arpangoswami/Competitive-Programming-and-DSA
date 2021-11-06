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
	int n,c;
	cin >> n >> c;
	map<int,int> mp;
	int ans = 0;
	for(int i=0;i<n;i++){
		int l,r;
		cin >> l >> r;
		if((r-l) == 0){
			continue;
		}
		ans++;
		if((r-l) == 1){
			continue;
		}
		mp[l+1]++;
		mp[r]--;
	}
	int currSum = 0;
	map<int,int> prefAdd;
	for(auto it:mp){
		prefAdd[it.first] = currSum;
		currSum += it.second;
	}
	for(auto &it:mp){
		it.second += prefAdd[it.first];
	}
	priority_queue<pii> pq;
	for(auto it:mp){
		pq.push({it.second,it.first});
	}
	while(!pq.empty() && c > 0){
		pii temp = pq.top();
		pq.pop();
		int cutAt = temp.second;
		int intervals = temp.first;
		if(intervals < 1){
			continue;
		}
		auto it = mp.upper_bound(cutAt);
		int maxLimit = (*it).first-1;
		int cutsMade = min((maxLimit-cutAt+1),c);
		ans += (cutsMade*intervals);
		c -= cutsMade;
	}
	cout<<ans<<"\n";
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
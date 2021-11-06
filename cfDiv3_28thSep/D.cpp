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
	vpi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].ff;
		arr[i].ss = i+1;
	}
	sort(arr.begin(),arr.end());
	if(n <= 1 || arr[n-2].ff == 0){
		cout<<"0\n";
		return;
	}
	multiset<pii> mset;
	for(int i=0;i<n;i++){
		if(arr[i].ff > 0){
			mset.insert(arr[i]);
		}
	}
	vector<pii> ans;
	while(mset.size() >= 2){
		auto it1 = mset.begin();		
		int talks = (*it1).ff,idx1 = (*it1).ss;
		mset.erase(it1);
		auto it2 = mset.end();
		it2--;
		int t2 = (*it2).ff,idx2 = (*it2).ss;
		mset.erase(it2);
		ans.push_back({idx1,idx2});
		if(talks > 1){
			mset.insert({talks-1,idx1});
		}
		if(t2 > 1){
			mset.insert({t2-1,idx2});
		}
	}
	cout<<ans.size()<<"\n";
	for(pii x:ans){
		cout<<x.ff<<" "<<x.ss<<"\n";
	}
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
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
void allPermutations(string &s,int idx,vector<string> &v){
	if(idx == s.size()){
		v.push_back(s);
		return;
	}
	for(int i=idx;i<s.size();i++){
		swap(s[i],s[idx]);
		allPermutations(s,idx+1,v);
		swap(s[i],s[idx]);
	}
}
int maxSplitProduct(string x){
	int n = x.size();
	int ans = 0;
	for(int i=1;i<n;i++){
		if(x[i] == '0'){
			continue;
		}
		int v1 = stoll(x.substr(0,i));
		int v2 = stoll(x.substr(i));
		ans = max(ans,v1*v2);
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s = to_string(n);
	vector<string> allPerms;
	allPermutations(s,0,allPerms);
	int ans = 0;
	set<string> st(allPerms.begin(),allPerms.end());
	for(string x:st){
		if(x[0] == '0'){
			continue;
		}
		int v = maxSplitProduct(x);
		ans = max(ans,v);
	}
	cout << ans << "\n";
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
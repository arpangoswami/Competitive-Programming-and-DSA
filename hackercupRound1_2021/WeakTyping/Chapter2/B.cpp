/*
2
11
OFXXFXFOOXF
13
OFXXFXFOOFOXF
*/
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
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
int firstIdx(const string &s,int n,char c){
	for(int i=0;i<n;i++){
		if(s[i] == c){
			return i;
		}
	}
	return n;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int fIdxX = firstIdx(s,n,'X'),fIdxO = firstIdx(s,n,'O');
	if(fIdxX == n || fIdxO == n){
		cout<<"0\n";
		return;
	}
	int ans = 0;
	vector<int> o_let,x_let;
	o_let.push_back(-1);
	x_let.push_back(-1);
	int start = 0;

	vector<pii> pref(n);
	if(s[0] == 'O'){
		o_let.push_back(0);
	}else if(s[0] == 'X'){
		x_let.push_back(0);
	}
	if(fIdxO < fIdxX){
		start ^= 1;
	}
	pref[0].ss = start;

	for(int i=1;i<n;i++){
		pref[i] = pref[i-1];
		if(start == 1 && s[i] == 'X'){
			start ^= 1;
			pref[i].ff += (o_let.back() - x_let.back());
			pref[i].ff %= MOD;
			pref[i].ss = start;
			x_let.push_back(i);
		}else if(start == 0 && s[i] == 'O'){
			start ^= 1;
			pref[i].ff += (x_let.back() - o_let.back());
			pref[i].ff %= MOD;
			pref[i].ss = start;
			o_let.push_back(i);
		}else if(s[i] == 'O'){
			o_let.push_back(i);
		}else if(s[i] == 'X'){
			x_let.push_back(i);
		}
	}
	// for(pii x:pref){
	// 	cout<<x.ff<<" "<<x.ss<<"\n";
	// }
	// cout<<"\n\n";

	vector<int> dp(n);
	
	for(int i=1;i<n;i++){
		dp[i] = dp[i-1];
		if(pref[i].ss != pref[i-1].ss){
			dp[i] += pref[i].ff;
		}
	}
	// for(int x:dp){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n\n";
	for(int x:dp){
		ans += x;
		ans %= MOD;
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("B_input.txt", "r", stdin);

	freopen("B_output.txt", "w", stdout);

	#endif
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}
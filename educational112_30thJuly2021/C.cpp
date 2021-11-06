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
	vi first(n+2),pref(n+2);
	vi second(n+2),suff(n+2);
	int score = 0;
	for(int i=1;i<=n;i++){
		cin >> first[i];
		score += first[i];
	}
	for(int i=1;i<=n;i++){
		cin >> second[i];
		score += second[i];
	}
	for(int i=1;i<=n;i++){
		pref[i] = pref[i-1] + second[i];
	}
	for(int i=n;i>=1;i--){
		suff[i] = suff[i+1] + first[i];
	}
	//minimize score only 1 down move
	for(int i=1;i<=n;i++){
		score = min(score,max(pref[i-1],suff[i+1]));
	}
	cout<<score<<"\n";
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
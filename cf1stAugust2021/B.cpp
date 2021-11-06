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
	string opp,same;
	cin >> opp >> same;
	vector<bool> reach(n,false);
	for(int i=0;i<n;i++){
		if(same[i] == '1'){
			if(i > 0 && opp[i-1] == '1' && !reach[i-1]){
				reach[i-1] = true;
			}else if(opp[i] == '0' && !reach[i]){
				reach[i] = true;
			}else if(i<(n-1) && opp[i+1] == '1' && !reach[i+1]){
				reach[i+1] = true;
			}
		}
	}
	int ans = 0;
	for(bool x:reach){
		ans += x;
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
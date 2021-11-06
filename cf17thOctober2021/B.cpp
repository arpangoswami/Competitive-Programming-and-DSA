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
	int n,m;
	cin >> n >> m;
	set<int> notPath;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		notPath.insert(b);
	}
	int missing = 0;
	for(int i=1;i<=n;i++){
		if(!notPath.count(i)){
			missing = i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i == missing){
			continue;
		}
		cout<<i<<" "<<missing<<"\n";
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
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
	int m,n;
	cin >> m >> n;
	vector<string> grid(m);
	for(string &x:grid){
		cin >> x;
	}
	vector<int> pref(n);
	for(int j=1;j<n;j++){
		for(int i=1;i<m;i++){
			if(grid[i-1][j] == 'X' && grid[i][j-1] == 'X'){
				pref[j]++;
			}
		}
	}
	for(int i=1;i<n;i++){
		pref[i] += pref[i-1];
	}
	int queries;
	cin >> queries;
	while(queries--){
		int col1,col2;
		cin >> col1 >> col2;
		//0 based indexing
		col2--;
		col1--;
		//left most column can always escape
		col1++;
		int nonExitDots = pref[col2] - pref[col1-1];
		if(nonExitDots <= 0){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
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
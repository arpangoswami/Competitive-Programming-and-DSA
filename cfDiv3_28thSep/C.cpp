/*
2
4 4 1
*.*.
****
.**.
....
5 5 1
.....
*...*
.*.*.
..*.*
...*.
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
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<string> grid(n);
	vector<vector<bool>> visited(m,vector<bool>(n,false));
	for(int i=0;i<n;i++){
		cin >> grid[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '.'){
				continue;
			}
			int d = 0;
			while(d < i && d < j && ((j+d+1) < m) && grid[i-d-1][j-d-1] != '.' && grid[i-d-1][j+d+1] != '.'){
				d++;
			}
			if(d >= k){
				for(int l=0;l<=d;l++){
					grid[i-l][j-l] = 'X';
					grid[i-l][j+l]='X';
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '*'){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
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
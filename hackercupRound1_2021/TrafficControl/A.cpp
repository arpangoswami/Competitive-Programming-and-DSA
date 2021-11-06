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
void solveQuestion(){
	int m,n,a,b;
	cin >> m >> n >> a >> b;
	vector<vector<int>> grid(m,vector<int> (n,1));
	for(int i=1;i<(m-1);i++){
		for(int j=1;j<(n-1);j++){
			grid[i][j] = 1e3;
		}
	}
	if((m + n - 2) >= a || (m + n - 2) >= b){
		cout<<"Impossible\n";
		return;
	}
	grid[m-1][n-1] = a - m - n + 2;
	grid[m-1][0] = b - m - n + 2;
	cout<<"Possible\n";
	for(auto v:grid){
		for(int x:v){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("A_input.txt", "r", stdin);

	freopen("A_output.txt", "w", stdout);

	#endif
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}
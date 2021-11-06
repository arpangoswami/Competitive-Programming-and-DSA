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
	int h,w;
	cin >> h >> w;
	vector<vector<char>> board(h,vector<char>(w,'0'));
	for(int j=0;j<w;j+=2){
		board[0][j] = '1';
		board[h-1][j] = '1';
	}
	for(int i=2;i<=(h-3);i+=2){
		board[i][0] = '1';
		board[i][w-1] = '1';
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<board[i][j];
		}
		cout<<"\n";
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
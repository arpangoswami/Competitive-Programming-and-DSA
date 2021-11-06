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
bool check(int x,int y,int bx,int by,vector<vector<char>> &grid,char fill){
	for(int i=x;i<bx;i++){
		for(int j=y;j<by;j++){
			if(grid[i][j] != fill){
				return false;
			}
		}
	}
	return true;
}
bool checkWinner(char fill,int x,int y,int n,int m,int k,vector<vector<char>> &grid){
	grid[x][y] = fill;
	for(int i=0;i<=(n-k);i++){
		for(int j=0;j<=(m-k);j++){
			if(check(i,j,i+k,j+k,grid,fill)){
				return true;
			}
		}
	}
	return false;
}
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<char>> grid(n,vector<char>(m));
	int moves = n*m;
	int winner = 0;
	for(int i=0;i<moves;i++){
		int x,y;
		cin >> x >> y;
		x--,y--;
		if(winner > 0){
			continue;
		}
		if(i % 2 == 0){
			bool f = checkWinner('A',x,y,n,m,k,grid);
			if(f){
				winner = 1;
			}
		}else{
			bool f = checkWinner('B',x,y,n,m,k,grid);
			if(f){
				winner = 2;
			}
		}
	}
	if(winner == 0){
		cout<<"Draw\n";
	}else if(winner == 1){
		cout<<"Alice\n";
	}else{
		cout<<"Bob\n";
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
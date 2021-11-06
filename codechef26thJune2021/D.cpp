/*
https://www.codechef.com/LTIME97B/problems/TICTACTO
Two drunken players Alice and Bob are playing a modified version of Tic-Tac-Toe.

Initially, there is a N×M empty grid.

Alice and Bob take alternate turns starting with Alice. In her turn, Alice chooses an empty cell on the board and puts a "A" on the chosen cell. In Bob's turn, he chooses an empty cell and puts a "B" on the chosen cell.

The player who first gets any K×K subgrid completely filled with his/her initial wins the game. By a K×K subgrid, we mean the intersection of K consecutive rows and K consecutive columns. The players do not stop making turns after one of them wins and they play all N⋅M turns until the grid is filled.

You are given the sequence of moves played by each player (The cell selected by the player in his/her turn). You have to output the winner of the game or report that there is no winner.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The first line of each test case contains three integers N, M, K.
Each of the next N⋅M lines contains two integers X, Y (the row and column of the cell chosen by the player with the current turn)
Output
For each test case, output "Alice" if Alice wins the game or "Bob" if Bob wins the game or "Draw" if no one wins.

Constraints
1≤T≤105
1≤N,M≤1000
1≤K≤min(N,M)
1≤X≤N
1≤Y≤M
The sum of N⋅M over all test cases does not exceed 106.
Subtasks
Subtask 1 (10 points): 1≤N≤10, 1≤M≤10
Subtask 2 (20 points): 1≤N≤50, 1≤M≤50
Subtask 3 (70 points): Original Constraints

Sample Input
1
3 4 2
1 1
3 1
1 2
2 3
2 1
2 4
3 2
3 4
1 3
3 3
2 2
1 4
Sample Output
Bob
Explanation
After 10 turns of the game the state of the grid is:

AAA.
A.BB
BABB
At this moment, Bob has achieved a subgrid of 2×2 with his initials while Alice has not achieved it yet so Bob is the winner.

All submissions for this problem are available.
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
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
int calSum(vector<vector<int>> &pref,int tlx,int tly,int brx,int bry){
	return pref[brx][bry] - ((tlx > 0) ? pref[tlx-1][bry] : 0) - ((tly > 0) ? pref[brx][tly-1] : 0) + ((tlx > 0 && tly > 0) ? pref[tlx-1][tly-1] : 0);
}
bool check(vector<pii> &moves,int mvPlayed,int n,int m,int k){
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i=1;i<=mvPlayed;i++){
		int place = (i & 1) ? 1 : -1;
		grid[moves[i].ff-1][moves[i].ss-1] = place;
	}
	vector<vector<int>> pref(n,vector<int>(m));
	pref[0][0] = grid[0][0];
	for(int i=1;i<m;i++){
		pref[0][i] = pref[0][i-1] + grid[0][i];
	}
	for(int i=1;i<n;i++){
		pref[i][0] = pref[i-1][0] + grid[i][0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			pref[i][j] = grid[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		}
	}
	for(int i=0;i<=(n-k);i++){
		for(int j=0;j<=(m-k);j++){
			int sm = calSum(pref,i,j,i+k-1,j+k-1);
			if(abs(sm) == k*k){
				return true;
			}
		}
	}
	return false;
}
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<pii> moves(n*m+1);
	for(int i=1;i<=(n*m);i++){
		cin >> moves[i].ff >> moves[i].ss;
	}
	int low = 1,high = n*m,ans = n*m+1;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(moves,mid,n,m,k)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	if(ans > n*m){
		cout<<"Draw\n";
	}else if(ans & 1){
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
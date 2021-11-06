/*
I guess the n-queen problem is known by every person who
has studied backtracking. In this problem you should count
the number of placement of n queens on an n ∗ n board so
that no two queens attack each other. To make the problem a little bit harder (easier?), there are some bad squares
where queens cannot be placed. Please keep in mind that bad
squares cannot be used to block queens’ attack.
Even if two solutions become the same after some rotations
and reflections, they are regarded as different. So there are
exactly 92 solutions to the traditional 8-queen problem.
Input
The input consists of at most 10 test cases. Each case contains
one integers n (3 ≤ n ≤ 15) in the first line. The following n lines represent the board, where empty
squares are represented by dots ‘.’, bad squares are represented by asterisks ‘*’. The last case is followed
by a single zero, which should not be processed.
Output
For each test case, print the case number and the number of solutions.
Sample Input
8
........
........
........
........
........
........
........
........
4
.*..
....
....
....
0
Sample Output
Case 1: 92
Case 2: 1
*/
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
void nQueens(int i,int n,vector<string> &board,bitset<30> &col,bitset<30> &d1,bitset<30> &d2,int &cnt){
	if(i == n){
		cnt++;
		return;
	}
	for(int j=0;j<n;j++){
		if(!col[j] && board[i][j] == '.' && !d1[i-j+n-1] && !d2[i+j]){
			col[j] = d1[i-j+n-1] = d2[i+j] = 1;
			nQueens(i+1,n,board,col,d1,d2,cnt);
			col[j] = d1[i-j+n-1] = d2[i+j] = 0;
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	int t = 1;
	while(cin>>n && n){
		bitset<30> col;
		bitset<30> d1;
		bitset<30> d2;
		vector<string> board(n);
		for(int i=0;i<n;i++){
			cin>>board[i];
		}
		int cnt = 0;
		vector<vector<bool>> placed(n,vector<bool>(n,false));
		nQueens(0,n,board,col,d1,d2,cnt);
		cout<<"Case "<<t<<": "<<cnt<<endl;
		t++;
	}
	return 0;
}
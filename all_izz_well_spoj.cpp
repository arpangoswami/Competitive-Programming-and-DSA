/*https://www.spoj.com/problems/ALLIZWEL/
#dfs
ALL IZZ WELL
Problem Description:

     Mr.ESP used to tell “ALL IZZ WELL” whenever he gets into any trouble. So his friends and the people around him used to laugh at him. But Mr.ESP is very strong in his belief. He believes that the term “ALL IZZ WELL” will make everything fine. Now your task is to ignore the story above and find whether there is a path in the given matrix which makes the sentence “ALL IZZ WELL”

     There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.

Input Specification:

     The first line consists of an integer t representing the number of test cases.

     The first line of each test case consists of two integers R and C representing the number of rows and number of columns in the matrix. The description of the matrix follows.

Output Specification:

     For each test case print “YES” if there is a path which makes the sentence “ALLIZZWELL”. Else print “NO”.

Note: Take care of 4th test case

There is a new line after every test case in the input.

Input constraints:

t <= 1000
R <= 100
C <= 100

Sample Input:

5
3 6
AWE.QX
LLL.EO
IZZWLL

1 10
ALLIZZWELL

2 9
A.L.Z.E..
.L.I.W.L.

3 3
AEL
LWZ
LIZ

1 10
LLEWZZILLA

Sample Output:
YES
YES
NO
NO
YES*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
const string path = "ALLIZZWELL";
const int len = 10;
bool isSafe(int x,int y,int m,int n,vector<vector<bool>> &visited) {
	return ((x>=0) && (y>=0) && (x<m) && (y<n) && !visited[x][y]);
}
bool pathExist(int idx, int x, int y, int m, int n, vector<string> &board, vector<vector<bool>> &visited) {
	if (idx == len) {
		return true;
	}
	visited[x][y] = true;
	for (int i = 0; i < 8 ; i++){
		int nx = x+dx[i],ny = y+dy[i];
		if(isSafe(nx,ny,m,n,visited) && board[nx][ny] == path[idx]){
			bool flag = pathExist(idx+1,nx,ny,m,n,board,visited);
			if(flag){
				return true;
			}
		}
	}
	visited[x][y] = false;
	return false;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int m, n;
		cin >> m >> n;
		vector<string> board(m);
		for (int i = 0; i < m; i++) {
			cin >> board[i];
		}
		vector<vector<bool>> visited(m,vector<bool>(n,false));
		bool f = false;
		for(int i=0;i<m && !f;i++){
			for(int j=0;j<n && !f;j++){
				if(board[i][j] == 'A'){
					f = pathExist(1,i,j,m,n,board,visited);
				}
			}
		}
		if(f){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}
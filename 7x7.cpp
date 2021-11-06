#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool canPlace(int num,vector<vector<int>> &board,vector<vector<char>> &region,int x,int y,char c){
	for(int k=0;k<7;k++){
		if(board[x][k] == num || board[k][y] == num){
			return false;
		}
	}
	for(int p=0;p<7;p++){
		for(int q=0;q<7;q++){
			if(p == x && q == y){
				continue;
			}
			if(region[p][q] == c && board[p][q] == num){
				return false;
			}
		}
	}
	return true;
}
bool sudokuSolve(vector<vector<int>> &board,vector<vector<char>> &region,int i,int j){
	if(i == 7){
		return true;
	}
	if(j == 7){
		return sudokuSolve(board,region,i+1,0);
	}
	if(board[i][j] != 0){
		return sudokuSolve(board,region,i,j+1);
	}
	for(int x=1;x<=7;x++){
		bool f = canPlace(x,board,region,i,j,region[i][j]);
		if(f){
			board[i][j] = x;
			bool flag = sudokuSolve(board,region,i,j+1);
			if(flag){
				return true;
			}
		}
	}
	board[i][j] = 0;
	return false;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> board(7,vector<int>(7));
	vector<vector<char>> region(7,vector<char> (7));
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cin >> board[i][j];
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cin >> region[i][j];
		}
	}
	sudokuSolve(board,region,0,0);
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
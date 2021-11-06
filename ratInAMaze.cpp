#include<iostream>
#include<vector>
#include<string>
using namespace std;
int rows[2] = {0,1};
int cols[2] = {1,0};
bool isSafe(int i,int j,int m,int n,vector<string> &board){
	return ((i>=0) && (j>=0) && (i<m) && (j<n) && board[i][j] == 'O');
}
int ans = 0;
bool rat_in_a_maze(int i,int j,int m,int n,vector<string> &board,int **grid){
	if(i == m-1 && j==n-1){
		grid[i][j] = 1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
		ans++;
		grid[i][j] = 0;
		cout<<endl;
		return true;
	}
	grid[i][j] = 1;
	for(int x=0;x<2;x++){
		if(isSafe(i+rows[x],j+cols[x],m,n,board)){
			bool canSolve = rat_in_a_maze(i+rows[x],j+cols[x],m,n,board,grid);
			if(canSolve){
				return true;
			}
		}
	}
	grid[i][j] = 0;
	return false;
}
int main() {
	int row,col;
	cin>>row>>col;
	int **grid = new int *[row];
	vector<string> board(row);
	for(int i=0;i<row;i++){
		grid[i] = new int[col]();
		cin>>board[i];
	}
	if(board[0][0] == 'X'){
		cout<<-1<<endl;
	}
	else if(board[row-1][col-1] == 'X'){
		cout<<-1<<endl;
	}
	else{
		bool flag = rat_in_a_maze(0,0,row,col,board,grid);
		if(ans == 0){
			cout<<-1<<endl;
		}
	}
	for(int i=0;i<row;i++){
		delete []grid[i];
	}
	delete []grid;
	return 0;
}
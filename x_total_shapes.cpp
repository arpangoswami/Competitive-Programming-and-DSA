#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool isSafe(int x,int y,int m,int n,vector<vector<bool>> &visited,vector<string> &board){
	return ((x>=0) && (y>=0) && (x<m) && (y<n) && !visited[x][y] && board[x][y] == 'X');
}
void dfs(int x,int y,int m,int n,vector<vector<bool>> &visited,vector<string> &board){
	visited[x][y] = true;
	for(int i=0;i<4;i++){
		if(isSafe(x+dx[i],y+dy[i],m,n,visited,board)){
			dfs(x+dx[i],y+dy[i],m,n,visited,board);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int rows,cols;
		cin>>rows>>cols;
		vector<string> board(rows);
		for(int i=0;i<rows;++i){
			cin>>board[i];
		}
		int ans = 0;
		vector<vector<bool>>visited(rows,vector<bool>(cols,false));
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(!visited[i][j] && board[i][j] == 'X'){
					ans++;
					dfs(i,j,rows,cols,visited,board);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
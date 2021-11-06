#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool isSafe(int x,int y,int m,int n,vector<vector<char>> &grid,vector<vector<bool>> &visited){
	return ((x>=0) && (y>=0) && (x<m) && (y<n) && grid[x][y] == '.' && !visited[x][y]);
}
void dfs(int x,int y,int m,int n,vector<vector<char>> &grid,vector<vector<bool>> &visited){
	visited[x][y] = true;
	for(int i=0;i<4;i++){
		if(isSafe(x+dx[i],y+dy[i],m,n,grid,visited)){
			dfs(x+dx[i],y+dy[i],m,n,grid,visited);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n;
	cin>>m>>n;
	vector<vector<char>> grid(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	int cnt = 0;
	vector<vector<bool>> visited(m,vector<bool>(n,false));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == '.' && !visited[i][j]){
				cnt++;
				dfs(i,j,m,n,grid,visited);
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
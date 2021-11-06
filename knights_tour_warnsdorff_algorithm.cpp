#include <bits/stdc++.h>
#define N 8
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
void print(vector<vector<int>> &grid) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}
bool isSafe(vector<vector<int>> &grid, int x, int y) {
	return ((x >= 0) && (y >= 0) && (x < N) && (y < N) && grid[x][y] == -1);
}
int getDegree(vector<vector<int>> &grid,int x,int y){
	int cnt = 0;
	for(int i=0;i<N;i++){
		if(isSafe(grid,x + dx[i],y + dy[i])){
			cnt++;
		}
	}
	return cnt;
}
bool solve(vector<vector<int>> &grid,int toPlace,int x,int y){
	if(toPlace == N*N + 1){
		return true;
	}
	int minIdx = -1,minDegree = (N+1);
	for(int i=0;i<N;i++){
		int next_x = x+dx[i],next_y = y+dy[i];
		if(isSafe(grid,next_x,next_y) && getDegree(grid,next_x,next_y) < minDegree){
			minIdx = i;
			minDegree = getDegree(grid,next_x,next_y);
		}
	}
	if(minIdx == -1){
		return false;
	}
	grid[x+dx[minIdx]][y+dy[minIdx]] = toPlace;
	return solve(grid,toPlace+1,x+dx[minIdx],y+dy[minIdx]);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> grid(N,vector<int>(N,-1));
	int sx,sy;
	cin>>sy>>sx;
	grid[sx-1][sy-1] = 1;
	bool flag = solve(grid,2,sx-1,sy-1);
	if(flag)
		print(grid);
	else 
		cout<< " Solution doesn't exist "<<"\n";
	return 0;
}
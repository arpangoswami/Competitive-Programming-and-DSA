#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int rows[4] = {-1,0,0,1};
int cols[4] = {0,-1,1,0};
bool withinGrid(int x,int y,int m,int n){
	return ((x>=0) && (y>=0) && (x<m) && (y<n));
}
bool isSafe(int x,int y,int m,int n,vector<vector<bool>> &visited,vector<string> &grid){
	return ((x>=0) && (y>=0) && (x<m) && (y<n) && !visited[x][y] && (grid[x][y] == 'G' || grid[x][y] == '.'));
}
bool dfs(int x,int y,int m,int n,vector<vector<bool>> &visited,vector<string> &grid){
	if(x == m-1 && y == n-1){
		return true;
	}
	visited[x][y] = true;
	for(int idx=0;idx<4;idx++){
		if(isSafe(x+rows[idx],y+cols[idx],m,n,visited,grid)){
			bool pathExist = dfs(x+rows[idx],y+cols[idx],m,n,visited,grid);
			if(pathExist){
				return true;
			}
		}
	}
	return false;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		vector<string> grid(m);
		for(int i=0;i<m;i++){
			cin>>grid[i];
		}
		bool f = true;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j] == 'B'){
					for(int idx=0;idx<4;idx++){
						if(withinGrid(i+rows[idx],j+cols[idx],m,n)){
							if(grid[i+rows[idx]][j+cols[idx]] == 'G'){
								f = false;
								break;
							}else if(grid[i+rows[idx]][j+cols[idx]] == '.'){
								grid[i+rows[idx]][j+cols[idx]] = '#';
							}
						}
					}
				}
				if(!f){
					break;
				}
			}
			if(!f){
				break;
			}
		}
		if(f){
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(grid[i][j] == 'G'){
						vector<vector<bool>> visited(m,vector<bool>(n,false));
						bool pathExist = dfs(i,j,m,n,visited,grid);
						if(!pathExist){
							f = false;
							break;
						}
					}
					if(!f){
						break;
					}
				}
				if(!f){
					break;
				}
			}
		}
		if(f){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
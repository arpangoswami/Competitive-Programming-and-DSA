#include<iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int rows[4] = {-1,0,0,1};
int cols[4] = {0,-1,1,0};
bool isSafe(int i,int j,int m,int n,vector<vector<int>> &grid){
	return ((i>=0) && (j>=0) && (i<m) && (j<n) && grid[i][j] == 2);
} 
int main(int argc,char const* argv[]){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	queue<pii> q;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == 1){
				q.push({i,j});
			}
		}
	}
	q.push({-1,-1});
	int ans = 0;
	while(!q.empty()){
		pii delivery = q.front();
		q.pop();
		int x = delivery.first,y = delivery.second;
		if(x == -1 && y == -1 && !q.empty()){
			ans++;
			q.push({-1,-1});
		}
		else{
			for(int i=0;i<4;i++){
				if(isSafe(x+rows[i],y+cols[i],m,n,grid)){
					grid[x+rows[i]][y+cols[i]] = 1;
					q.push({x+rows[i],y+cols[i]});
				}
			}
		}	
	}
	cout<<ans<<"\n";
	return 0;
}
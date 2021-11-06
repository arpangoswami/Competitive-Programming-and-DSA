#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool isSafe(vector<string> &grid,int x,int y,int n,int m,vector<vector<bool>> &visited){
	return (x>=0 && y>=0 && x<n && y<m && grid[x][y] == '.' && !visited[x][y]);
}
string reachTheEnd(vector<string> grid,int maxTime){
	int n = grid.size();
	if(n == 0){
		return "Yes";
	}
	int m = grid[0].size();
	vector<vector<int>> dist(n,vector<int>(m,1e9));
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	queue<pii> Q;
	Q.push({0,0});
	dist[0][0] = 0;
	visited[0][0] = true;
	while(!Q.empty()){
		pii temp = Q.front();
		Q.pop();
		int x_co = temp.first,y_co = temp.second;
		for(int k=0;k<4;k++){
			if(isSafe(grid,x_co + dx[k],y_co + dy[k],n,m,visited)){
				Q.push({x_co + dx[k],y_co + dy[k]});
				dist[x_co + dx[k]][y_co + dy[k]] = 1 + dist[x_co][y_co];
				visited[x_co + dx[k]][y_co + dy[k]] = true;
			}
		}
	}
	return dist[n-1][m-1] <= maxTime ? "Yes" : "No";
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<string> grid(n);
	for(int i=0;i<n;i++){
		cin >> grid[i];
	}
	int k;
	cin >> k;
	cout<<reachTheEnd(grid,k);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
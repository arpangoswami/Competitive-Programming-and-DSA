#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int rows[4] = { -1, 0, 0, 1};
int cols[4] = {0, -1, 1, 0};
bool withinGrid(int x, int y, int m, int n) {
	return ((x >= 0) && (y >= 0) && (x < m) && (y < n));
}
bool isSafe(int x, int y, int m, int n, vector<vector<bool>> &visited, vector<string> &grid) {
	return ((x >= 0) && (y >= 0) && (x < m) && (y < n) && !visited[x][y] && (grid[x][y]!='#'));
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int m, n;
		cin >> m >> n;
		vector<string> grid(m);
		for (int i = 0; i < m; i++) {
			cin >> grid[i];
		}
		bool f = true;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'B') {
					for (int idx = 0; idx < 4; idx++) {
						if (withinGrid(i + rows[idx], j + cols[idx], m, n)) {
							if (grid[i + rows[idx]][j + cols[idx]] == 'G') {
								f = false;
								break;
							} else if (grid[i + rows[idx]][j + cols[idx]] == '.') {
								grid[i + rows[idx]][j + cols[idx]] = '#';
							}
						}
					}
				}
				if (!f) {
					break;
				}
			}
			if (!f) {
				break;
			}
		}
		if(grid[m-1][n-1] == '#'){
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(grid[i][j] == 'G'){
						f = false;
						break;
					}
				}
				if(!f){
					break;
				}
			}
		}
		if (f) {
			vector<vector<bool>> visited(m,vector<bool>(n,false));
			queue<pii> q;
			if(grid[m-1][n-1] == '.'){
				q.push({m-1,n-1});
				visited[m-1][n-1] = true;
			}
			while(!q.empty()){
				pii box = q.front();
				q.pop();
				int x_co = box.first,y_co = box.second;
				for(int idx=0;idx<4;idx++){
					if(isSafe(x_co+rows[idx],y_co+cols[idx],m,n,visited,grid)){
						q.push({x_co+rows[idx],y_co+cols[idx]});
						visited[x_co+rows[idx]][y_co+cols[idx]] = true;
					}
				}
			}
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(grid[i][j] == 'G' && !visited[i][j]){
						f = false;
						break;
					}else if(grid[i][j] == 'B' && visited[i][j]){
						f = false;
						break;
					}
				}
				if(!f){
					break;
				}
			}
		}
		if (f) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
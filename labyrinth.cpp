#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dx[4] = { -1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
struct box {
	int x_co;
	int y_co;
	int distance;
	box() {
		x_co = -1;
		y_co = -1;
		distance = 1e9;
	}
	box(int x, int y, int dist) {
		x_co = x;
		y_co = y;
		distance = dist;
	}
};
inline bool isSafe(int x, int y, int m, int n, vector<vector<bool>> &visited,vector<vector<char>> &grid) {
	return ((x >= 0) && (y >= 0) && (x < m) && (y < n) && grid[x][y] != '#' && !visited[x][y]);
}
string tracePath(int x,int y,vector<vector<pii>> &mp){
	string ans;
	while(x!=-1 && y!=-1){
		pii temp = mp[x][y];
		int par_x = temp.first,par_y = temp.second;
		for(int i=0;i<4;i++){
			if(x+dx[i] == par_x && y+dy[i] == par_y){
				if(i == 0){
					ans.push_back('D');
				}else if(i == 1){
					ans.push_back('R');
				}else if(i == 2){
					ans.push_back('L');
				}else{
					ans.push_back('U');
				}
			}
		}
		x = par_x;
		y = par_y;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
void bfs(int x, int y, int m, int n,vector<vector<char>> &grid) {
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	queue<box> q;
	q.push(box(x, y, 0));
	map<pii,pii> mp;
	visited[x][y] = true;
	vector<vector<pii>> parent(m,vector<pii>(n));
	parent[x][y] = {-1,-1};
	bool flag = false;
	int len = m*n + 1;
	int destX = -1,destY = -1;
	while (!q.empty()) {
		box temp = q.front();
		q.pop();
		int x = temp.x_co, y = temp.y_co, dist = temp.distance;
		if(grid[x][y] == 'B'){
			flag = true;
			destX = x;
			destY = y;
			len = dist;
			break;
		}
		for(int i=0;i<4;i++){
			if(isSafe(x+dx[i],y+dy[i],m,n,visited,grid)){
				parent[x+dx[i]][y+dy[i]] = {x,y};
				visited[x+dx[i]][y+dy[i]] = true;
				q.push(box(x+dx[i],y+dy[i],dist+1));
			}
		}
	}
	if(!flag)
		cout << "NO" << "\n";
	else{
		cout<< "YES" <<"\n";
		cout<< len <<"\n";
		string path = tracePath(destX,destY,parent);
		cout<<path<<"\n";
	}
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	cin >> m >> n;
	vector<vector<char>> grid(m,vector<char>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	bool **visited = new bool* [m];
	for(int i=0;i<m;i++){
		visited[i] = new bool[n]();
	}
	bool f = false;
	for (int i = 0; i < m && !f; i++) {
		for (int j = 0; j < n && !f; j++) {
			if (grid[i][j] == 'A') {
				bfs(i, j, m, n, grid);
				f = true;
			}
		}
	}
	for(int i=0;i<m;i++){
		delete []visited[i];
	}
	delete []visited;
	return 0;
}
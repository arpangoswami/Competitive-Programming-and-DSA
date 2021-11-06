#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF = 2e9;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void solveQuestion(){
	int h,w;
	cin >> h >> w;
	int sx,sy,destX,destY;
	cin >> sx >> sy;
	cin >> destX >> destY;
	sx--;
	sy--;
	destX--;
	destY--;
	vector<string> grid(h);
	for(int i=0;i<h;i++){
		cin >> grid[i];
	}
	auto isValid = [&](int x,int y){
		return ((x >= 0) && (y >= 0) && (x < h) && (y < w));
	};
	deque<pii> q;
	vector<vector<int>> dist(h,vector<int>(w,INF));
	q.push_back({sx,sy});
	dist[sx][sy] = 0;
	while(!q.empty()){
		int row = q.front().ff,col = q.front().ss;
		q.pop_front();
		if(row == destX && col == destY){
			cout << dist[destX][destY] << "\n";
			return;
		}
		for(int k=0;k<4;k++){
			int nr = row + dx[k],nc = col+dy[k];
			if(!isValid(nr,nc) || grid[nr][nc] == '#' || dist[nr][nc] <= dist[row][col]){
				continue;
			}
			q.push_front({nr,nc});
			dist[nr][nc] = dist[row][col];
		}
		for(int i=-2;i<=2;i++){
			for(int j=-2;j<=2;j++){
				int nr = row + i,nc = col + j;
				if(!isValid(nr,nc) || grid[nr][nc] == '#' || dist[nr][nc] <= 1 + dist[row][col]){
					continue;
				}
				q.push_back({nr,nc});
				dist[nr][nc] = 1 + dist[row][col];
			}
		}
	}
	cout << -1 <<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
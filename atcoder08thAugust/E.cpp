#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int stepSize = 2;
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};
void solveQuestion(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> grid(h,vector<char>(w));
	for(int i=0;i<h;i++){
		string s;
		cin >> s;
		for(int j=0;j<w;j++){
			grid[i][j] = s[j];
		}
	}
	vector<vector<int>> d(h,vector<int>(w,h*w+1));
	auto valid = [&](int x,int y){
		return ((x >= 0) && (y >= 0) && (x < h) && (y < w));
	};
	deque <pii> q;
	q.push_back({0,0});
	d[0][0] = 0;
	while(!q.empty()){
		int row = q.front().ff, col = q.front().ss;
		q.pop_front();
		if(row == h-1 && col == w-1){
			cout << d[h-1][w-1] << "\n";
			return;
		}
		for(int k=0;k<4;k++){
			int nr = row + dx[k],nc = col+dy[k];
			if(!valid(nr,nc) || grid[nr][nc] == '#'){
				continue;
			}
			if (d[nr][nc] <= d[row][col]){
                continue;
            }
            d[nr][nc] = d[row][col];
            q.push_front({nr,nc});
		}
		for(int i=-2;i<=2;i++){
			for(int j=-2;j<=2;j++){
				if(abs(i) + abs(j) == 4 || abs(i) + abs(j) == 0){
					continue;
				}
				int nr = row + i,nc = col + j;
				if(!valid(nr,nc)){
					continue;
				}
				if(d[nr][nc] <= d[row][col] + 1){
					continue;
				}
				d[nr][nc] = d[row][col] + 1;
				q.push_back({nr,nc});
			}
		}
	}
	
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
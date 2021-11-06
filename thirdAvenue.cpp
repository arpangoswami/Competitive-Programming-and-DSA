#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int h,w;
inline bool isSafe(int x,int y,vector<vector<char>> &arr,vector<vector<bool>> &visited){
	return ((x>=0) && (y >=0) && (x<h) && (y<w) && arr[x][y]!='#' && !visited[x][y]);
}
void solveQuestion(){
	cin >> h >> w;
	pii start = {0,0};
	vector<vector<char>> arr(h,vector<char>(w));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'S'){
				start = {i,j};
			}
		}
	}
	vector<vector<int>>dist(h,vector<int>(w,1e9));
	queue<pii> q;
	q.push(start);
	vector<vector<bool>> visited(h,vector<bool>(w,false));
	dist[start.first][start.second] = 0;
	visited[start.first][start.second] = true;
	unordered_set<char> st;
	while(!q.empty()){
		pii temp = q.front();
		q.pop();
		char ch = arr[temp.first][temp.second];
		if(ch == 'G'){
			cout<<dist[temp.first][temp.second];
			return;
		}
		if(ch >= 'a' && ch <= 'z' && st.count(ch) == 0){
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					if(arr[i][j] == ch && !visited[i][j]){
						dist[i][j] = 1 + dist[temp.first][temp.second];
						q.push({i,j});
						visited[i][j] = true;
					}
				}
			}
			st.insert(ch);
		}
		int x_co = temp.first,y_co = temp.second;
		for(int k=0;k<4;k++){
			if(isSafe(x_co + dx[k],y_co + dy[k],arr,visited)){
				dist[x_co+dx[k]][y_co+dy[k]] = 1 + dist[x_co][y_co];
				visited[x_co+dx[k]][y_co+dy[k]] = true;
				q.push({x_co+dx[k],y_co+dy[k]});
			}
		}
	}
	cout<<-1;
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
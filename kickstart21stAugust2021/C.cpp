#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x,y;
	cin >> x >> y;
	vector<string> grid(x);
	for(string &s:grid){
		cin >> s;
	}
	vector<vector<array<int,3>>> hori(x,vector<array<int,3>>(y));
	vector<vector<array<int,3>>> vert(x,vector<array<int,3>>(y));
	for(int i=0;i<x;i++){
		for(int j=0;j<y;){
			if(grid[i][j] == '#'){
				j++;
				continue;
			}
			int len = 1;
			int startJ = j;
			while(j < y && grid[i][j] != '#'){
				len++;
				j++;
			}
			for(int k=startJ;k<j;k++){
				hori[i][k] = {len,startJ,j-1};
			}
		}
	}
	for(int j=0;j<y;j++){
		for(int i=0;i<x;){
			if(grid[i][j] == '#'){
				i++;
				continue;
			}
			int len = 1;
			int startI = i;
			while(i < x && grid[i][j] != '#'){
				len++;
				i++;
			}
			for(int k=startI;k<i;k++){
				vert[k][j] = {len,startI,i-1};
			}
		}
	}
	vector<vector<bool>> visited(x,vector<bool>(y,false));
	queue<pii> q;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(grid[i][j] != '.' && grid[i][j] != '#'){
				q.push({i,j});
				visited[i][j] = true;
			}
		}
	}
	int ans = 0;
	while(!q.empty()){
		int i = q.front().ff,j = q.front().ss;
		q.pop();
		int sameRow = hori[i][j][1] + hori[i][j][2] - j;
		int sameCol = vert[i][j][1] + vert[i][j][2] - i;
		if(sameRow >= 0 && sameRow < y && !visited[i][sameRow] && grid[i][sameRow] == '.'){
			ans++;
			grid[i][sameRow] = grid[i][j];
			q.push({i,sameRow});
			visited[i][sameRow] = true;
		}
		if(sameCol >= 0 && sameCol < x && !visited[sameCol][j] && grid[sameCol][j] == '.'){
			ans++;
			grid[sameCol][j] = grid[i][j];
			q.push({sameCol,j});
			visited[sameCol][j] = true;
		}
	}
	cout<<ans<<"\n";
	for(int i=0;i<x;i++){
		cout<<grid[i]<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}
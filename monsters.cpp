/*
Monsters
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneoulsy take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input

The first input line has two integers n and m: the height and width of the map.

After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

Output

First print "YES" if your goal is possible, and "NO" otherwise.

If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R. You can print any path, as long as its length is at most n⋅m steps.

Constraints
1≤n,m≤1000
Example

Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
char dir[4] = {'U','L','R','D'};
bool isSafe(int x,int y,int ht,int wd,vector<vector<bool>> &visited,vector<string> &grid){
	return ((x>=0) && (y>=0) && (x<ht) && (y<wd) && !visited[x][y] && grid[x][y]!='#');
}
void bfs(queue<vector<int>> &q,map<pii,int> &mp,vector<vector<bool>> &visited,int ht,int wd,vector<string> &grid){
	while(!q.empty()){
		vector<int> temp = q.front();
		q.pop();
		int x_co = temp[0],y_co = temp[1],steps = temp[2];
		if(((x_co == 0 || x_co == ht-1) || (y_co == 0 || y_co == wd-1)) && grid[x_co][y_co] == '.'){
			mp[{x_co,y_co}] = steps;
		}
		for(int k=0;k<4;k++){
			if(isSafe(x_co + dx[k],y_co+dy[k],ht,wd,visited,grid)){
				visited[x_co+dx[k]][y_co+dy[k]] = true;
				q.push({x_co+dx[k],y_co+dy[k],steps+1});
			}
		} 
	}
}
bool dfs(string &s,int svx,int svy,int destX,int destY,int ht,int wd,int steps,vector<vector<bool>> &visited,vector<string> &grid){
	if(svx == destX && svy == destY && steps == 0){
		return true;
	}
	visited[svx][svy] = true;
	for(int k=0;k<4;k++){
		if(isSafe(svx+dx[k],svy+dy[k],ht,wd,visited,grid)){
			s.push_back(dir[k]);
			bool f = dfs(s,svx+dx[k],svy+dy[k],destX,destY,ht,wd,steps-1,visited,grid);
			if(f){
				return true;
			}
			s.pop_back();
		}
	}
	visited[svx][svy] = false;
	return false;

}
void solveQuestion(){
	int ht,wd;
	cin >> ht >> wd;
	int x = -1,y = -1;
	queue<vector<int>> q;
	vector<string> grid(ht);
	vector<vector<bool>> visited(ht,vector<bool>(wd,false));
	for(int i=0;i<ht;i++){
		cin >> grid[i];
		for(int j=0;j<wd;j++){
			if(grid[i][j] == 'A'){
				x = i;
				y = j;
			}else if(grid[i][j] == 'M'){
				q.push({i,j,0});
				visited[i][j] = true;
			}
		}
	}
	if(x == 0 || x == ht-1 || y == 0 || y == wd-1){
		cout<<"YES"<<"\n";
		cout<<0<<"\n";
		return;
	}
	map<pii,int> mpMonster;
	bfs(q,mpMonster,visited,ht,wd,grid);
	for(int i=0;i<ht;i++){
		for(int j=0;j<wd;j++){
			visited[i][j] = false;
		}
	}
	map<pii,int> mpPerson;
	q.push({x,y,0});
	visited[x][y] = true;
	bfs(q,mpPerson,visited,ht,wd,grid);
	map<pii,int> solution;
	for(auto it:mpPerson){
		if(mpMonster.count({(it.first).first,(it.first).second}) == 0 || mpMonster[{(it.first).first,(it.first).second}] > it.second){
			solution[{(it.first).first,(it.first).second}] = it.second;
		}
	}
	if(solution.size() == 0){
		cout<<"NO"<<"\n";
	}else{
		cout<<"YES"<<"\n";
		string s;
		pii dest = (solution.begin())->first;
		int steps = (solution.begin())->second;
		for(int i=0;i<ht;i++){
			for(int j=0;j<wd;j++){
				visited[i][j] = false;
			}
		}
		dfs(s,x,y,dest.first,dest.second,ht,wd,steps,visited,grid);
		cout<<steps<<"\n";
		cout<<s<<"\n";
	}
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
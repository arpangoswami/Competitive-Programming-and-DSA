#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int rows[8] = {-1,-2,-2,-1,1,2,2,1};
int cols[8] = {-2,-1,1,2,2,1,-1,-2};
struct node{
	int x_co,y_co,level;
	node(int x,int y,int l){
		x_co = x;
		y_co = y;
		level = l;
	}
};
bool isSafe(int x,int y,int n,vector<vector<bool>> &visited){
	return ( (x>=0) && (y>=0) && (x<n) && (y<n) && !(visited[x][y]) );
}
int bfs(int sx,int sy,int fx,int fy,int n){
	vector<vector<bool>> visited(n,vector<bool>(n,false));
	node nd = node(sx,sy,0);
	queue<node> q;
	q.push(nd);
	visited[sx][sy] = true;
	int ans = -1;
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		int x = temp.x_co,y = temp.y_co;
		int lvl = temp.level;
		if(x == fx && y == fy){
			return lvl;
		}
		for(int i=0;i<8;i++){
			int newX = x+rows[i],newY = y+cols[i],newLvl = lvl+1;
			if(isSafe(newX,newY,n,visited)){
				q.push(node(newX,newY,newLvl));
				visited[newX][newY] = true;
			}
		}
	}
	return ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int sx,sy;
		cin>>sx>>sy;
		int fx,fy;
		cin>>fx>>fy;
		int minSteps = bfs(sx-1,sy-1,fx-1,fy-1,n);
		cout<<minSteps<<"\n";
	}
	return 0;
}
/*NAKANJ - Minimum Knight moves !!!
#bfs
Anjali and Nakul are good friends. They both had a quarrel recently while playing chess. Nakul wants to know the minimum number of moves a knight takes to reach from one square to another square of a chess board (8X8). Nakul is brilliant and he had already written a program to solve the problem. Nakul wants to know whether Anjali can do it. Anjali is very weak in programming. Help her to solve the problem.

A knight can move in the shape of an "L" in a chessboard - two squares either forward, backward, left, or right and then one square to its left or right. A knight move is valid if it moves as mentioned above and it is within the boundary of the chessboard (8 X 8).

knight

Input
There are T test cases in total. The next T lines contain two strings (start and destination) separated by a space.

The strings start and destination will only contain two characters - First character is an alphabet between 'a' and 'h' (inclusive), Second character is a digit between '1' and '8' (inclusive) - (Quotes just for clarity).

To know the knight moves more clearly refer to the above figure.

Output
Print the minimum number of moves a knight takes to reach from start to destination in a separate line.

Constarints
1 <= T <= 4096

Example
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
bool isSafe(int x,int y,int m,int n,vector<vector<bool>> &visited){
	return ((x>=0) && (y>=0) && (x<m) && (y<n) && !visited[x][y]);
}
struct box{
	int x;
	int y;
	int lvl;
	box(int x,int y,int lvl){
		this->x = x;
		this->y = y;
		this->lvl = lvl;
	}
};
int bfs(int x_start,int y_start,int x_end,int y_end,int m,int n){
	vector<vector<bool>> visited(m,vector<bool>(n,false));
	queue<box> q;
	q.push(box(x_start,y_start,0));
	visited[x_start][y_start] = true;
	while(!q.empty()){
		box present = q.front();
		q.pop();
		int x = present.x,y = present.y,level = present.lvl;
		if(x == x_end && y == y_end){
			return level;
		}
		for(int i = 0;i<8;i++){
			if(isSafe(x+dx[i],y+dy[i],m,n,visited)){
				int newX = x+dx[i],newY = y+dy[i];
				q.push(box(newX,newY,level+1));
				visited[newX][newY] = true;
			}
		}
	}
	return -1;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		char start,end;
		int st,en;
		string x,y;
		cin>>x>>y;
		start = x[0],st = x[1] - 48,end = y[0],en = y[1]-48;
		int y_start = start - 'a',x_start = 8 - st;
		int y_end = end - 'a',x_end = 8 - en;
		cout<<bfs(x_start,y_start,x_end,y_end,8,8)<<endl;
	}
	return 0;
}
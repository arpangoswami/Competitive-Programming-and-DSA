/*https://www.spoj.com/problems/MAXWOODS/
MAXWOODS - MAXIMUM WOOD CUTTER
#dynamic-programming
Problem Statement:


The image explains it all. You initially step at 0,0 facing right.
 At each step you can move according to the conditions specified in the image.
  You cannot step into the blocked boxes (in blue). Find the maximum number of trees you can cut.

Input:

The first line consists of an integer t, the number of test cases.
 For each test case the first line consists of two integers m and n, the number of rows and columns.
  Then follows the description of the matrix M.

M[i][j]=’T’ if the region has a tree.

M[i][j]=’#’ if the region is blocked.

M[i][j]=’0’ (zero) otherwise.

Output:

 

For each test case find the maximum trees that you can cut.

 

Input Constraints:

1<=t<=10

1<=m,n<=200

 

Example:

Sample Input:

4
5 5
0TTTT
T#T#0
#TT#T
T00T0
T0#T0
1 1
T
3 3
T#T
TTT
T#T
1 1
#
Sample Output:

8
1
3
0
Solution for test case #1:


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[205][205][2];
int solve(int i,int j,int state,int m,int n,vector<string> &grid){
	if(i>=m || j>=n || j<0 || i<0 || grid[i][j] == '#'){
		return 0;
	}
	if(dp[i][j][state]!=-1){
		return dp[i][j][state];
	}
	int ans = 0;
	if(grid[i][j] == 'T'){
		ans++;
	}
	if(state == 1){
		ans += max(solve(i,j+1,1,m,n,grid),solve(i+1,j,0,m,n,grid));
	}else{
		ans += max(solve(i,j-1,0,m,n,grid),solve(i+1,j,1,m,n,grid));
	}
	return dp[i][j][state] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		memset(dp,-1,sizeof(dp));
		vector<string> grid(m);
		for(int i=0;i<m;i++){
			cin>>grid[i];
		}
		if(grid[0][0] == '#'){
			cout<<0<<endl;
		}else{
			cout<<solve(0,0,1,m,n,grid)<<endl;
		}
	}
	return 0;
}
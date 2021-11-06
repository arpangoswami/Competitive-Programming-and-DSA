/*
E - Queen on Grid  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

https://atcoder.jp/contests/abc183/tasks/abc183_e

Sample Input 1 
Copy
3 3
...
.#.
...
Sample Output 1 
Copy
10
Sample Input 2 
Copy
4 4
...#
....
..#.
....
Sample Output 2 
Copy
84


Sample Input 3 
Copy
8 10
..........
..........
..........
..........
..........
..........
..........
..........
Sample Output 3 
Copy
13701937
Find the count modulo 1e9 + 7
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
void solveQuestion(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> grid(h,vector<char>(w));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> grid[i][j];
		}
	}
	vector<vector<int>> x(h,vector<int>(w));
	vector<vector<int>> y(h,vector<int>(w));
	vector<vector<int>> z(h,vector<int>(w));
	vector<vector<int>> dp(h,vector<int>(w));
	dp[h-1][w-1] = 1;
	for(int i=h-1;i>=0;i--){
		for(int j=w-1;j>=0;j--){
			if(i == h-1 && j == w-1){
				continue;
			}
			if(grid[i][j] == '#'){
				continue;
			}
			if(i < (h-1)){
				y[i][j] = (y[i+1][j] + dp[i+1][j])%MOD;
			}
			if(j < (w-1)){
				x[i][j] = (x[i][j+1] + dp[i][j+1])%MOD;
			}
			if(i < (h-1) && j < (w-1)){
				z[i][j] = (z[i+1][j+1] + dp[i+1][j+1])%MOD;
			}
			dp[i][j] = (x[i][j] + y[i][j] + z[i][j])%MOD;
		}
	}
	cout<<dp[0][0];
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
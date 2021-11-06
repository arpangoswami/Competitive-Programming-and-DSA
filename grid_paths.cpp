/*
Grid Paths
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

For example, the path

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.

Input

The only input line has a 48-character string of characters ?, D, U, L and R.

Output

Print one integer: the total number of paths.

Example

Input:
??????R??????U??????????????????????????LD????D?

Output:
201
*/
#include <bits/stdc++.h>
#define int long long
#define N 7
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
char dir[4] = {'U','L','R','D'};
string s;
int ans = 0;
vector<vector<bool>> visited(N,vector<bool>(N,false));
bool isSafe(int i,int j){
	return ((i>=0) && (j>=0) && (i<N) && (j<N) && !visited[i][j]);
}
void solve(int i,int j,int idx = 0){
	if(i == N-1 && j == 0){
        if(idx == 48){
            ans++;
        }
        return;
    }
	visited[i][j] = true;
	if(s[idx] == '?' || s[idx] == 'L'){
        if(j && !visited[i][j-1]){
            if(!(!(isSafe(i,j-2)) && isSafe(i+1,j-1) && isSafe(i-1,j-1))){
                solve(i,j-1,idx+1);
            }
        }
    }
    if(s[idx] == '?' || s[idx] == 'R'){
        if(j < 6 && !visited[i][j+1]){
            if(!(!isSafe(i,j+2) && isSafe(i+1,j+1) && isSafe(i-1,j+1))){
                solve(i,j+1,idx+1);
            }
        }
    }
    if(s[idx] == '?' || s[idx] == 'U'){
        if(i && !visited[i-1][j]){
            if(!(!isSafe(i-2,j) && isSafe(i-1,j-1) && isSafe(i-1,j+1))){
                solve(i-1,j,idx+1);
            }
        }
    }
    if(s[idx] == '?' || s[idx] == 'D'){
        if(i < 6 && !visited[i+1][j]){
            if(!(!isSafe(i+2,j) && isSafe(i+1,j+1) && isSafe(i+1,j-1))){
                solve(i+1,j,idx+1);
            }
        }
    }
	visited[i][j] = false;
}
void solveQuestion(){
	cin >> s;
	vector<vector<bool>> visited(7,vector<bool>(7,false));
	solve(0,0);
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}
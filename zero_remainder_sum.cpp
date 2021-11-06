/*
F. Zero Remainder Sum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a matrix a of size n×m consisting of integers.

You can choose no more than ⌊m/2⌋ elements in each row. Your task is to choose these elements in such a way that their sum is divisible by k and this sum is the maximum.

In other words, you can choose no more than a half (rounded down) of elements in each row, you have to find the maximum sum of these elements divisible by k.

Note that you can choose zero elements (and the sum of such set is 0).

Input
The first line of the input contains three integers n, m and k (1≤n,m,k≤70) — the number of rows in the matrix, the number of columns in the matrix and the value of k. The next n lines contain m elements each, where the j-th element of the i-th row is ai,j (1≤ai,j≤70).

Output
Print one integer — the maximum sum divisible by k you can obtain.

Examples
inputCopy
3 4 3
1 2 3 4
5 2 2 2
7 1 1 4
outputCopy
24
inputCopy
5 5 4
1 2 4 2 1
3 5 1 2 4
1 5 7 1 2
3 8 7 1 2
8 4 7 1 6
outputCopy
56
Note
In the first example, the optimal answer is 2 and 4 in the first row, 5 and 2 in the second row and 7 and 4 in the third row. The total sum is 2+4+5+2+7+4=24.


*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,m,k;
int dp[71][71][36][71];
int mat[71][71];
int solve(int i,int j,int picked,int rem){
	if(i == n){
		if(rem == 0){
			return dp[i][j][picked][rem] = 0;
		}
		return dp[i][j][picked][rem] = -1e5;
	}
	if(j == m){
		return dp[i][j][picked][rem] = solve(i+1,0,0,rem);
	}
	if(dp[i][j][picked][rem]!=-1){
		return dp[i][j][picked][rem];
	}
	if(picked < (m/2)){
		return dp[i][j][picked][rem] = max(mat[i][j] + solve(i,j+1,picked+1,(rem + mat[i][j])%k),solve(i,j+1,picked,rem));
	}
	return dp[i][j][picked][rem] = solve(i,j+1,picked,rem);
}
void solveQuestion(){
	cin >> n >> m >> k;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> mat[i][j];
		}
	}
	cout<<solve(0,0,0,0);
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
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[501][501];
inline int calSum(vector<vector<int>> &arr,int col,int start,int end){
	if(end < start){
		return 0;
	}
	if(start == 0){
		return arr[end][col];
	}else{
		return (arr[end][col] - arr[start-1][col]);
	}
}
int recSolve(int col,int picked,vector<vector<int>> &prefColA,vector<vector<int>> &prefColB,int m,int n){
	if(col == n){
		return dp[col][picked] = 0;
	}
	if(dp[col][picked] != -1){
		return dp[col][picked];
	}
	int ans = 0;
	for(int i=picked;i<=m;i++){
		int x = calSum(prefColA,col,0,i-1),y = calSum(prefColB,col,i,m-1);
		int temp = x + y + recSolve(col+1,i,prefColA,prefColB,m,n);
		ans = max(ans,temp);
	}
	return dp[col][picked] = ans;
}
void solveQuestion(int m,int n){
	vector<vector<int>> A(m,vector<int>(n));
	vector<vector<int>> B(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> B[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> A[i][j];
		}
	}
	vector<vector<int>> prefColA(m,vector<int>(n));
	vector<vector<int>> prefColB(m,vector<int>(n));
	for(int j=0;j<n;j++){
		prefColA[0][j] = A[0][j];
		prefColB[0][j] = B[0][j];
		for(int i=1;i<m;i++){
			prefColA[i][j] = prefColA[i-1][j] + A[i][j];
			prefColB[i][j] = prefColB[i-1][j] + B[i][j];
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	int ans = 0;
	for(int i=0;i<=m;i++){
		int x = calSum(prefColA,0,0,i-1),y = calSum(prefColB,0,i,m-1);
		int temp = calSum(prefColA,0,0,i-1) + calSum(prefColB,0,i,m-1) + recSolve(1,i,prefColA,prefColB,m,n);
		ans = max(ans,temp);
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true){
		int m,n;
		cin >> m >> n;
		if(m == 0 && n == 0){
			break;
		}
		solveQuestion(m,n);
	}
	return 0;
}
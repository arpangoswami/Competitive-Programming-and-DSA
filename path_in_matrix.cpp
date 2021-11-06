#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	int **arr = new int *[n]();
	int **dp = new int *[n]();
	for(int i=0;i<n;i++){
		arr[i] = new int[n]();
		dp[i] = new int[n]();
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	for(int j=0;j<n;j++){
		dp[n-1][j] = arr[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<n;j++){
			int left = (j == 0) ? 0 : dp[i+1][j-1];
			int right = (j == n-1) ? 0 : dp[i+1][j+1];
			int bottom = dp[i+1][j];
			dp[i][j] = arr[i][j] + max({left,right,bottom});
		}
	}
	int ans = 0;
	for(int j=0;j<n;j++){
		if(dp[0][j] > ans){
			ans = dp[0][j];
		}
	}
	cout<<ans<<"\n";
	for(int i=0;i<n;i++){
		delete []arr[i];
		delete []dp[i];
	}
	delete []arr;
	delete []dp;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
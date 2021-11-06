#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int findMaxHeight(int i,int j,vector<vector<int>> &dp,int m,int n){
	int ht = min({dp[i][j],j+1,n-j});
	int left = ht,right = ht,req = ht-1;
	for(int col=j-1;col>=0 && req > 0;col--,req--){
		if(dp[i][col] < req){
			left = min(left,j-col + dp[i][col]);
		}
	}
	req = ht-1;
	for(int col = j+1;col < n && req > 0;col++,req--){
		if(dp[i][col] < req){
			right = min(right,col-j+dp[i][col]);
		}
	}
	return min(left,right);
}
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	vector<vector<char>> arr(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> dp(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == '.'){
				dp[i][j] =  0;
			}else if(arr[i][j] == '*'){
				if(i > 0){
					dp[i][j] = dp[i-1][j] + 1;
				}else{
					dp[i][j] = 1;
				}
			}
		}
	}
	vector<vector<int>> cache(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j])
				cache[i][j] = findMaxHeight(i,j,dp,m,n);
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ans += cache[i][j];
		}
	}
	cout<<ans<<'\n';
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
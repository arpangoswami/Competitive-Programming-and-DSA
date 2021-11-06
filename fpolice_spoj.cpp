#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		int n,t;
		cin >> n >> t;
		vector<vector<int>> time(n+1,vector<int>(n+1));
		vector<vector<int>> risk(n+1,vector<int>(n+1));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> time[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> risk[i][j];
			}
		}
		vector<vector<int>> dp(n+1,vector<int>(t+1,1e9));
		dp[0][0] = 0;
		int tm = -1;
		for(int k=1;k<=t;k++){
			for(int j=0;j<n;j++){
				dp[j][k] = dp[j][k-1];
				for(int i=0;i<n;i++){
					if(time[i][j] > k){
						continue;
					}
					dp[j][k] = min(dp[j][k],dp[i][k-time[i][j]] + risk[i][j]);
				}
			}
			if(dp[n-1][k] != dp[n-1][k-1]){
				tm = k;
			}
		}
		if(tm == -1){
			cout<<tm<<'\n';
		}else{
			cout<<dp[n-1][tm]<<" "<<tm<<'\n';
		}
	}
	return 0;
}
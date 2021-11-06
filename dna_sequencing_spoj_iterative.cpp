#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true){
		int k;
		cin>>k;
		if(k == 0){
			break;
		}
		string a,b;
		cin>>a>>b;
		int m = a.size(),n = b.size();
		vector<vector<int>> subarray(m+1,vector<int>(n+1,0));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i-1] == b[j-1]){
					subarray[i][j] = 1+subarray[i-1][j-1];
				}
			}
		}
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(subarray[i][j]>=k){
					for(int x=k;x<=subarray[i][j];x++){
						dp[i][j] = max(dp[i][j],dp[i-x][j-x] + x);
					}
				}
			}
		}
		cout<<dp[m][n]<<"\n";
	}
	return 0;
}
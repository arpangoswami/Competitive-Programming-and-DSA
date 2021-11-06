#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<vector<int> > dp(n,vector<int>(3,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>dp[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if(j == 0){
				dp[i][j] += max(dp[i-1][1],dp[i-1][2]);
			}
			else if(j == 1){
				dp[i][1] += max(dp[i-1][0],dp[i-1][2]);
			}
			else{
				dp[i][2] += max(dp[i-1][0],dp[i-1][1]);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<3;i++){
		ans = max(ans,dp[n-1][i]);
	}
	cout<<ans<<"\n";
	return 0;
}
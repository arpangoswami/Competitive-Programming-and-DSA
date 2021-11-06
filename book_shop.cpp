#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,money;
	cin>>n>>money;
	vector<int> prices(n);
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	vector<int> pages(n);
	for(int i=0;i<n;i++){
		cin>>pages[i];
	}
	vector<vector<int>> dp(2,vector<int>(money+1,0));
	for(int i=0;i<n;i++){
		int curr_row = (i+1)%2;
		int prev_row = 1-curr_row;
		for(int j=0;j<=money;j++){
			if(j>=prices[i]){
				dp[curr_row][j] = max(dp[prev_row][j],pages[i] + dp[prev_row][j - prices[i]]);
			}else{
				dp[curr_row][j] = dp[prev_row][j];
			}
		}
	}
	cout<<dp[n%2][money]<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int rows,cols;
		cin>>rows>>cols;
		int **grid = new int* [rows];
		int **dp = new int* [rows];
		for(int i=0;i<rows;++i){
			grid[i] = new int[cols]();
			dp[i] = new int[cols]();
		}
		for(int i=0;i<rows;++i){
			for(int j=0;j<cols;++j){
				cin>>grid[i][j];
			}
		}
		if(cols == 1){
			dp[rows-1][0] = grid[rows-1][0];
			for(int i=rows-2;i>=0;i--){
				dp[i][0] = dp[i+1][0] + grid[i][0];
			}
		}
		else if(cols>=2){
			for(int j=0;j<cols;++j){
				dp[rows-1][j] = grid[rows-1][j];
			}
			for(int i=rows-2;i>=0;i--){
				for(int j=0;j<cols;j++){
					if(j == 0){
						dp[i][j] = grid[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
					}
					else if(j == cols-1){
						dp[i][j] = grid[i][j] + max(dp[i+1][j],dp[i+1][j-1]);
					}
					else{
						dp[i][j] = grid[i][j] + max({dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]});
					}
				}
			}
		}
		int maxi = 0;
		for(int j=0;j<cols;++j){
			maxi = max(maxi,dp[0][j]);
		}
		cout<<maxi<<endl;
		for(int i=0;i<rows;++i){
			delete []grid[i];
			delete []dp[i];
		}
		delete []grid;
		delete []dp;
	}
	return 0;
}
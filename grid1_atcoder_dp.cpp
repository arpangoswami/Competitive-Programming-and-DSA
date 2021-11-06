#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll mod = 1e9L+7;
ll numberOfWays(int x,int y,vector<string> &grid,int m,int n,vector<vector<ll>> &dp){
	if(x >=m || y>=n){
		return 0;
	}
	if(x == m-1 && y == n-1){
		return 1;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	if(grid[x][y] == '#'){
		return dp[x][y] = 0;
	}
	ll ans1 = numberOfWays(x+1,y,grid,m,n,dp);
	ll ans2 = numberOfWays(x,y+1,grid,m,n,dp);
	return dp[x][y] = (ans1+ans2)%mod;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n;
	cin>>m>>n;
	vector<string> grid(m);
	for(int i=0;i<m;i++){
		cin>>grid[i];
	}
	vector<vector<ll>>dp(m,vector<ll>(n,-1));
	cout<<numberOfWays(0,0,grid,m,n,dp);
	return 0;
}
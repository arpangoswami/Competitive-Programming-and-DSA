#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int n,m,k;
int dp[501][501][21];
int leftRight[501][501];
int upDown[501][501];
int solve(int i,int j,int steps){
	if(steps == 0){
		return 0LL;
	}
	if(dp[i][j][steps] != -1){
		return dp[i][j][steps];
	}
	auto isSafe = [&](int x,int y){
		return (x >= 0 && y >= 0 && x < n && y < m);
	};
	int &ans = dp[i][j][steps];
	ans = 1e9;
	for(int k=0;k<4;k++){
		if(isSafe(i+dx[k],j+dy[k])){
			int u = i+dx[k],v = j+dy[k],wt = 1e9;
			if(k == 0){
				wt = upDown[i-1][j];
			}else if(k == 1){
				wt = leftRight[i][j-1];
			}else if(k == 2){
				wt = leftRight[i][j];
			}else if(k == 3){
				wt = upDown[i][j];
			}
			ans = min(ans,wt+solve(u,v,steps-1));
		}
	}
	return ans;
}
void solveQuestion(){
	cin >> n >> m >> k;
	if(k & 1){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << -1 << " ";
			}
			cout<<'\n';
		}
		return;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=20;k++){
				dp[i][j][k] = -1LL;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<(m-1);j++){
			cin >> leftRight[i][j];
		}
	}
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<m;j++){
			cin >> upDown[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int ans = solve(i,j,k/2);
			cout<<2*ans<<" ";
		}
		cout<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
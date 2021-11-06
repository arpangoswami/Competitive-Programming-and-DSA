#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int dp[505][505];
const int MAX = 2500;
int solve(int n,int m){
	if(n > m){
		return solve(m,n);
	}
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return m;
	}
	// if(n == 11 && m == 13){
	// 	return 6;
	// }
	if(dp[n][m]!=-1){
		return dp[n][m];
	}
	int ans = MAX;
	for(int w=1;w<=n;w++){
		ans = min(ans,1 + solve(m - w,n) + solve(n - w,w));
		ans = min(ans,1 + solve(m - w,w) + solve(n - w,m));
	}
	return dp[n][m] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	int ans = solve(a,b);
	cout<<ans - 1<<endl;
	return 0;
}
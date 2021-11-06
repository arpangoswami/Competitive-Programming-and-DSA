#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 2e17;
int dp[3001][3001][3];
int solve(vector<int> &font,vector<int> &cost,int idx,int lastPicked,int totalPicked,int n){
	if(totalPicked == 3){
		return 0;
	}
	if(idx == n){
		return inf;
	}
	if(dp[idx][lastPicked][totalPicked]!=-1){
		return dp[idx][lastPicked][totalPicked];
	}
	int ans = inf;
	if(font[idx] > font[lastPicked]){
		ans = min(ans,cost[idx] + solve(font,cost,idx+1,idx,totalPicked + 1,n));
	}
	ans = min(ans,solve(font,cost,idx+1,lastPicked,totalPicked,n));
	return dp[idx][lastPicked][totalPicked] = ans;
}	
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> font(n);
	for(int i=0;i<n;i++){
		cin >> font[i];
	}
	vector<int> cost(n);
	for(int i=0;i<n;i++){
		cin >> cost[i];
	}
	int ans = inf;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=2;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	for(int i=0;i<n;i++){
		ans = min(ans,cost[i] + solve(font,cost,i+1,i,1,n));
	}
	ans = ans >= inf ? -1 : ans;
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
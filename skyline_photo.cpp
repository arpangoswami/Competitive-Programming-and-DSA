#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vi heights;
vi beauty;
int dp[3001][3001];
int n;
int solve(int i,int minHtIndex){
	if(i == n){
		return beauty[minHtIndex];
	}
	if(dp[i][minHtIndex] != -1){
		return dp[i][minHtIndex];
	}
	int &ans = dp[i][minHtIndex];
	if(heights[i] < heights[minHtIndex]){
		ans = solve(i+1,i);
	}else{
		ans = solve(i+1,minHtIndex);
	}
	ans = max(ans,beauty[minHtIndex] + solve(i+1,i));
	return ans;
}
void solveQuestion(){
	cin >> n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	heights.resize(n);
	beauty.resize(n);

	for(int &i:heights){
		cin >> i;
	}
	for(int &i:beauty){
		cin >> i;
	}
	cout<<solve(1,0)<<'\n';
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
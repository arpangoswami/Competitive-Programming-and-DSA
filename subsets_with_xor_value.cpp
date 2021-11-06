#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int n,int xorTillNow,int req,vector<vector<int>> &dp){
    if(n == 0){
        return 0;
    }
    if(dp[xorTillNow][n]!=-1){
        return dp[xorTillNow][n];
    }
    dp[xorTillNow][n] = 0;
    return dp[xorTillNow][n] = solve(arr,n-1,xorTillNow ^ arr[n-1],req,dp) + solve(arr,n-1,xorTillNow,req,dp);
}
void solveQ(){
    int n,req;
    cin >> n >> req;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(128,vector<int>(n+1,-1));
    int ans = solve(arr,n,0,req,dp);
    cout<<ans<<"\n";
}
int main() {
	//code
	int test;
	cin >> test;
	while(test--){
	    solveQ();
	}
	return 0;
}
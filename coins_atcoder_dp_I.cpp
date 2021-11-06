/*https://atcoder.jp/contests/dp/tasks/dp_i*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
double heads(int n,int req,vector<double> &prob,vector<vector<double>> &dp){
	if(req == 0){
		return 1.00;
	}
	if(n == 0){
		return 0.00;
	}
	if(dp[n][req]!=-1){
		return dp[n][req];
	}
	return dp[n][req] = prob[n-1] * heads(n-1,req-1,prob,dp) + (1-prob[n-1]) * heads(n-1,req,prob,dp);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<double> prob(n);
	for(int i=0;i<n;i++){
		cin>>prob[i];
	}
	int majority = n/2 + 1;
	vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
	double ans = heads(n,majority,prob,dp);
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}
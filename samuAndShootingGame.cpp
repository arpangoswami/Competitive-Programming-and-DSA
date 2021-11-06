#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
double calMaxProb(int x,int y,int n,int w,double prob1,double prob2,vector<vector<double>> &dp){
	if(w<=0){
		return 1.0;
	}
	if(n == 0){
		return 0.0;
	}
	if(dp[n][w]!=-1){
		return dp[n][w];
	}
	double p1 = prob1*calMaxProb(x,y,n-1,w-x,prob1,prob2,dp) + (1-prob1)*calMaxProb(x,y,n-1,w,prob1,prob2,dp);
	double p2 = prob2*calMaxProb(x,y,n-1,w-y,prob1,prob2,dp) + (1-prob2)*calMaxProb(x,y,n-1,w,prob1,prob2,dp);
	return dp[n][w] = max(p1,p2);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int x,y,n,w;
		double p1,p2;
		cin>>x>>y>>n>>w>>p1>>p2;
		p1/=100.0;
		p2/=100.0;
		vector<vector<double>> dp(n+1,vector<double>(w+1,-1));
		double maxProb = calMaxProb(x,y,n,w,p1,p2,dp);
		maxProb*=100;
		cout<<setprecision(6)<<fixed<<maxProb<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k,p;
int dp[51][1550];
int maxBeautyValue(vector<vector<int>> &prefix,int idx,int taken){
	if(dp[idx][taken]!=-1){
		return dp[idx][taken];
	}
	if(taken == p) return dp[idx][taken];
	if(taken>p || idx>=n){
		return INT_MIN;
	}
	int ans = INT_MIN;
	for(int i=0;i<=k;i++){
		ans = max(ans,prefix[idx][i]+maxBeautyValue(prefix,idx+1,taken+i));
	}
	return dp[idx][taken] = ans;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    for(int x=1;x<=test;x++){
    	cin>>n>>k>>p;
    	memset(dp,-1,sizeof(dp));
        vector<vector<int>> prefix(n,vector<int>(k+1,0));
        for(int i=0;i<n;i++){
        	for(int j=1;j<=k;j++){
        		cin>>prefix[i][j];
        		prefix[i][j]+=prefix[i][j-1];
        	}
        }
        int ans = maxBeautyValue(prefix,0,0);
        cout<<"Case #"<<x<<": "<<ans+1<<endl;
    }
    return 0;
}
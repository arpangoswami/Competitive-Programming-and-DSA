/*https://atcoder.jp/contests/dp/tasks/dp_d*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct item{
	ll wt;
	ll val;
};
ll dp[105][100005];
ll knapsack(ll wt,ll n,vector<item> &things){
	if(wt == 0 || n == 0){
		return 0;
	}
	if(dp[n][wt]!=-1){
		return dp[n][wt];
	}
	ll ans1 = knapsack(wt,n-1,things);
	ll ans2 = INT_MIN;
	if(things[n-1].wt<=wt){
		ans2 = things[n-1].val+knapsack(wt-things[n-1].wt,n-1,things);
	}
	return dp[n][wt] = max(ans1,ans2);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,w;
	cin>>n>>w;
	vector<item> things(n);
	for(int i=0;i<n;i++){
		cin>>things[i].wt>>things[i].val;
	}
	memset(dp,-1,sizeof(dp));
	cout<<knapsack(w,n,things)<<endl;
	return 0;
}
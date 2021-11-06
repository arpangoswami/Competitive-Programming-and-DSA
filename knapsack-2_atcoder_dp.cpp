/*https://atcoder.jp/contests/dp/tasks/dp_e*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll inf = 1e12L;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,w;
	cin>>n>>w;
	vector<ll> weights(n);
	vector<ll> vals(n);
	ll sum_of_val = 0;
	for(int i=0;i<n;i++){
		cin>>weights[i]>>vals[i];
		sum_of_val+=vals[i];
	}
	vector<vector<ll>> dp(n+1,vector<ll>(sum_of_val+1,inf));
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum_of_val;j++){
			if(vals[i-1]<=j){
				dp[i][j] = min(dp[i-1][j],dp[i-1][j-vals[i-1]] + weights[i-1]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	ll ans = 0;
	for(int j=sum_of_val;j>=0;j--){
		if(dp[n][j] <= w){
			ans = j;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
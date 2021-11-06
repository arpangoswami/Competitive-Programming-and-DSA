#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2005][2005];
const ll mod = 1e9L + 7;
ll solve(int last,int n,int k){
	if(k == 0){
		return 1;
	}
	if(dp[last][k]!=-1){
		return dp[last][k];
	}
	int i = 1;
	ll ans = 0; 
	while(i*last <= n){
		ans+=solve(i*last,n,k-1);
		i++;
		ans%=mod;
	}
	return dp[last][k] = ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,k;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans+=solve(i,n,k-1);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
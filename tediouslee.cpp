#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll mod = 1e9L + 7;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	vector<ll> dp(2000001);
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2;i<=2000000;i++){
		dp[i] = (2*dp[i-2] + dp[i-1]) + (i%3 == 2 ? 1:0);
		dp[i]%=mod;
	}
	//cout<<dp[2]<<endl;
	while(test--){
		int n;
		cin>>n;
		n--;
		cout<<(dp[n]*4)%mod<<endl;
	}
	return 0;
}
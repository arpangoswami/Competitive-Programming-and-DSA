#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll const mod = 1e9 + 7;
ll dp[1000001];
ll f[1000001];
ll g[1000001];
ll h[1000001];
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;
	for (int j = 3; j <= 1e6; j++) {
		dp[j] = dp[j - 2];
		dp[j] += dp[j - 3];
		dp[j] %= mod;
	}
	f[0]=1;g[0]=0;h[0]=0;
	f[1]=1;g[1]=0;h[1]=0;
	f[2]=2;g[2]=0;h[2]=1;
	f[3]=3;g[3]=1;h[3]=1;
    for(int i=4;i<=1000000;i++){
        f[i]=(f[i-1]+2*g[i-2]+f[i-3])%mod;
	    g[i]=(h[i-1]+g[i-3])%mod;
	    h[i]=(h[i-3]+f[i-3])%mod;
    }
	int test;
	cin >> test;
	while (test--) {
		int k, n;
		cin >> k >> n;
		if (k == 1) {
			if (n % 3 == 0) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
		else if (k == 2) {
			cout << dp[n] << endl;
		} else if(k == 3) {
			cout << f[n-1] << endl;
		}
	}
	return 0;
}
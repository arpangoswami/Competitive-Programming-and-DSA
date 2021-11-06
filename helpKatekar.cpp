#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> arr(n);
	int maxm = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxm = max(maxm,arr[i]);
	}
	ll count = 0;
	vector<vector<ll>> dp(n,vector<ll>(maxm+1,0));
	for(int i=0;i<n;i++){
		dp[i][arr[i]]++;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				for(int k=1;k<=maxm;k++){
					int new_gcd = __gcd(k,arr[i]);
					dp[i][new_gcd]+=dp[j][k];
					dp[i][new_gcd]%=mod;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		count+=dp[i][1];
		count%=mod;
	}
	cout<<count<<endl;
	return 0;
}
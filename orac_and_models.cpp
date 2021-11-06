#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> allFactors(int n){
	vector<int>factors;
	factors.push_back(1);
	factors.push_back(n);
	int i;
	for(i=2;i*i<n;i++){
		if(n%i == 0){
			factors.push_back(i);
			factors.push_back(n/i);
		}
	}
	if(i*i == n){
		factors.push_back(i);
	}
	sort(factors.begin(),factors.end());
	return factors;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n+1);
		arr[0] = 0;
		for(int i=1;i<=n;++i){
			cin>>arr[i];
		}
		vector<int> dp(n+1,1);
		dp[0] = 0;
		dp[1] = 1;
		for(int i=2;i<=n;i++){
			vector<int>factors = allFactors(i);
			for(int j=0;j<factors.size();j++){
				if(arr[factors[j]]<arr[i] && factors[j]!=i){
					dp[i] = max(dp[i],1+dp[factors[j]]);
				}
			}
		}
		int maxi = 1;
		for(int i=1;i<=n;i++){
			maxi = max(maxi,dp[i]);
		}
		cout<<maxi<<"\n";
	}
	return 0;
}
#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr1(n);
	vi arr2(n);
	for(int &i:arr1){
		cin >> i;
	}
	for(int &i:arr2){
		cin >> i;
	}
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		dp[i][i] = arr1[i] * arr2[i];
	}
	for(int len = 2;len <= n;len++){
		for(int i=0;i<=(n-len);i++){
			int j = i+len-1;
			dp[i][j] = dp[i+1][j-1] + arr1[i]*arr2[j] + arr2[i]*arr1[j];
		}
	}
	vector<int> pref(n);
	pref[0] = arr1[0] * arr2[0];
	for(int i=1;i<n;i++){
		pref[i] = (arr1[i] * arr2[i]) + pref[i-1];
	}
	int ans = pref.back();
	auto calSum = [&](int i,int j){
		if(i > j){
			return 0LL;
		}
		if(i == 0){
			return pref[j];
		}
		return (pref[j] - pref[i-1]);
	};
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int fSum = calSum(0,i-1);
			int sSum = calSum(j+1,n-1);
			int rev = dp[i][j];
			ans = max(ans,fSum + sSum + rev);
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
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
int n;
vi arr;
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	int sm = 0;
	for(int &i:arr){
		cin >> i;
		sm += i;
	}
	if(sm % 2 != 0){
		cout << 0 << '\n';
		return;
	}
	bool dp[(sm/2 + 1)][n+1];
	for(int j=0;j<=n;j++){
		dp[0][j] = true;
	}
	for(int i=1;i<=(sm/2);i++){
		dp[i][0] = false;
	}
	for(int i=1;i<=(sm/2);i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1];
			if(i >= arr[j-1]){
				dp[i][j] = dp[i][j] || dp[i - arr[j - 1]][j - 1];
			}
		}
	}
	cout << dp[sm/2][n] << '\n';
	if(dp[sm/2][n] == false){
		return;
	}
	while(true){
		for(int i=0;i<n;i++){
			if(arr[i] % 2 == 1){
				cout << (i+1) << '\n';
				return;
			}
			arr[i]/=2;
		}
	}
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
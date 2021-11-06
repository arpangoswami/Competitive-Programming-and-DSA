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
	int n,k;
	cin >> n >> k;
	vi arr(n);
	unordered_map<int,int> mp[k];
	for(int i=0;i<n;i++){
		cin >> arr[i];
		mp[i%k][arr[i]]++;
	}
	int ans = 0;
	for(int i=0;i<k;i++){
		int maxEl = 0,sum = 0;
		for(auto it:mp[i]){
			sum += it.second;
			maxEl = max(maxEl,it.second);
		}
		ans += (sum - maxEl);
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
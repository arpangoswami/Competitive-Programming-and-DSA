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
const int MOD = 998244353;
const int sz = 2e5+5;
void solveQuestion(){
	int n;
	cin >> n;
	if(n == 1){
		cout<<"0\n";
		return;
	}
	for(int i=30;i>=0;i--){
		if((n >> i) & 1){
			int ans = (1LL << i) - 1;
			cout << ans << "\n";
			return;
		}
	}
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
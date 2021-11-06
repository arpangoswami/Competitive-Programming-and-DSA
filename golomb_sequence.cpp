#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int sum(int term){
	
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int left,right;
		cin >> left >> right;
		int ans1 = sum(right),ans2 = sum(left-1);
		cout << ans1 - ans2 << "\n";
	}
	return 0;
}
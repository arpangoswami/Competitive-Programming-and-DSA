#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string ans;
		int n,k;
		cin >> n >> k;
		while(n--){
			int val;
			cin >> val;
			if(val % k == 0){
				ans.push_back('1');
			}else{
				ans.push_back('0');
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
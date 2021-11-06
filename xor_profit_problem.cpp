#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin >> a >> b;
	int x = a ^ b;
	int ans = 0;
	int last = 0;
	for(int i=20;i>=0;i--){
		if(x >> i){
			last = i;
			break;
		}
	}
	ans = (1LL<<(last+1));
	ans--;
	cout << ans << "\n";
	return 0;
}
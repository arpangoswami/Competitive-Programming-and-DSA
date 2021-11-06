#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int curr_sum = 0;
		bool f = true;
		for(int i=0;i<n;i++){
			curr_sum += arr[i];
			if(curr_sum <= 0){
				f = false;
				break;
			}
		}
		curr_sum = 0;
		for(int i=n-1;i>=0;i--){
			curr_sum += arr[i];
			if(curr_sum <= 0){
				f = false;
				break;
			}
		}
		string ans = f ? "YES" : "NO" ;
		cout << ans << "\n";
	}
	return 0;
}
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
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int sum = 0;
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2) {
				odd++;
			} else {
				even++;
			}
			sum += arr[i];
		}
		if (x == n) {
			if (sum % 2 == 0) {
				cout << "No" << "\n";
			} else {
				cout << "Yes" << "\n";
			}
		}else if(odd == 0){
			cout<<"No"<<"\n";
		} else{
			if(even!=0){
				cout<<"Yes"<<"\n";
			}else{
				if(x%2 == 0){
					cout<<"No"<<"\n";
				}else{
					cout<<"Yes"<<"\n";
				}
			}
		}
	}
	return 0;
}
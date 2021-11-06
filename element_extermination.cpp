#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
4
10
7 2 8 9 5 10 1 6 4 3
5
4 3 1 5 2
7
2 4 6 1 5 7 3
7
4 7 3 6 1 5 2
*/
int main(int argc, char const* argv[]) {
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
		bool flag = true;
		if(arr[n-1] == 1){
			flag = false;
		}else if(arr[0]!=1){
			int val1 = arr[0];
			int val2 = arr[n-1];
			if(val1 > val2){
				flag = false;
			}
		}
		if (flag) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}
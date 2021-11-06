#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		set<int> original;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			original.insert(a);
		}
		bool flag = true;
		for (int i = 1; i <= 1023; i++) {
			set<int> cas;
			for (int x : original) {
				cas.insert(x ^ i);
			}
			if (original == cas) {
				cout << i << endl;
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << -1 << endl;
		}
	}
	return 0;
}
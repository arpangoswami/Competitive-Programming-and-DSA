#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void solveQuestion() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			continue;
		}
		else if (s[i] == '1') {
			if ((i - k) >= 0) {
				if (s[i - k] == '0') {
					cout << "NO" << "\n";
					return;
				} else if (s[i - k] == '?') {
					s[i - k] = '1';
				}
			}
			if ((i + k) < n) {
				if (s[i + k] == '0') {
					cout << "NO" << "\n";
					return;
				} else if (s[i + k] == '?') {
					s[i + k] = '1';
				}
			}
		}
		else if (s[i] == '0') {
			if ((i - k) >= 0) {
				if (s[i - k] == '1') {
					cout << "NO" << "\n";
					return;
				} else if (s[i - k] == '?') {
					s[i - k] = '0';
				}
			}
			if ((i + k) < n) {
				if (s[i + k] == '1') {
					cout << "NO" << "\n";
					return;
				} else if (s[i + k] == '?') {
					s[i + k] = '0';
				}
			}
		}
	}
	int zeros = 0, ones = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == '1') {
			ones++;
		} else if (s[i] == '0') {
			zeros++;
		}
	}
	for (int i = k; i < n; i++) {
		if (ones > (k / 2) || zeros > (k / 2)) {
			cout << "NO" << "\n";
			return;
		}
		if (s[i] == '1') {
			ones++;
		} else if (s[i] == '0') {
			zeros++;
		}
		if (s[i-k] == '1') {
			ones--;
		} else if (s[i-k] == '0') {
			zeros--;
		}
	}
	if (ones > k / 2 || zeros > k / 2) {
		cout << "NO" << "\n";
		return;
	}
	cout << "YES" << "\n";
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
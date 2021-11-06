#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int change(string &s, int left, int right, char c) {
	if (left == right) {
		if (s[left] == c) {
			return 0;
		}
		return 1;
	}
	int mid = (left + right) / 2;
	int cnt = 0;
	for (int i = left; i <= mid; i++) {
		if (s[i] != c) {
			cnt++;
		}
	}
	int id = c - 'a';
	char next = 'a' + id + 1;
	int cd1 = cnt + change(s, mid + 1, right, next);
	cnt = 0;
	for (int i = mid + 1; i <= right; i++) {
		if (s[i] != c) {
			cnt++;
		}
	}
	int cd2 = cnt + change(s, left, mid, next);
	return min(cd1, cd2);
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(n == 1){
			if(s[0] == 'a'){
				cout << 0 <<'\n';
			}else{
				cout<< 1 << "\n";
			}
			continue;
		}
		int ans = n;
		int left = 0,right = n-1;
		ans = min(ans,change(s,left,right,'a'));
		cout << (ans) << "\n";
	}
	return 0;
}
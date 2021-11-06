#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
void solveQuestion() {
	int n;
	cin >> n;
	vi arr(n);
	int mini = n;
	unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		st.insert(arr[i]);
	}
	//sort(arr.begin(), arr.end());
	int mex = 0;
	while(st.count(mex) != 0){
		mex++;
	}
	if (mex == 0) {
		int ans = 0;
		for (int i = 0; i < (n - 1); i++) {
			ans = (2 * ans + 1) % mod;
		}
		ans++;
		ans %= mod;
		cout << ans << '\n';
		return;
	}
	//cout<<"mex: "<<mex<<'\n';
	int ans = 0;
	vi present(mex, -1);
	vi suffix(n + 2);
	multiset<int> tillNow;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] < mex) {
			if (present[arr[i]] != -1) {
				tillNow.erase(tillNow.find(present[arr[i]]));
			}
			present[arr[i]] = i;
			tillNow.insert(i);
		}
		if (tillNow.size() == mex) {
			int MEX = *(tillNow.rbegin());
			ans = (ans + suffix[MEX + 1] + 1) % mod;
			suffix[i] = (suffix[i + 1] + suffix[MEX + 1] + 1) % mod;
		} else {
			suffix[i] = suffix[i + 1];
		}
	}

	cout << (suffix[0] - suffix[1] + mod) % mod << '\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
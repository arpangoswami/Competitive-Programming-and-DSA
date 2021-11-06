#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<pii, unordered_set<string>>dp;
unordered_set<string> wordBreak(string &s, unordered_set<string> &st, int i, int j) {
	if (dp.count({i, j})) {
		return dp[ {i, j}];
	}
	unordered_set<string> sol;
	if (i > j)
		return sol;
	if (st.count(s.substr(i, j - i + 1))) {
		sol.insert(s.substr(i, j - i + 1));
	}
	for (int k = i; k < j; k++) {
		unordered_set<string>left = wordBreak(s, st, i, k);
		unordered_set<string>right = wordBreak(s, st, k + 1, j);
		for (string x : left) {
			for (string y : right) {
				string temp = x + " " + y;
				sol.insert(temp);
			}
		}

	}
	dp[ {i, j}] = sol;
	return sol;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		unordered_set<string> st;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			st.insert(s);
		}
		string s;
		cin >> s;
		unordered_set<string> words = wordBreak(s, st, 0, s.size() - 1);
		vector<string> sol;
		for (string k : words) {
			sol.push_back(k);
		}
		sort(sol.begin(), sol.end());
		for (int i = 0; i < sol.size(); i++) {
			cout << "(" << sol[i] << ")";
		}
		cout << "\n";
	}
	return 0;
}
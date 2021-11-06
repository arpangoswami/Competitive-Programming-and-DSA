#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int wordSearch(string &s, unordered_set<string> &st, vector<vector<int>> &dp, int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (st.count(s.substr(i, j - i + 1))) {
		return dp[i][j] = 1;
	}
	for (int k = i; k < j; k++) {
		int left = wordSearch(s, st, dp, i, k);
		int right = wordSearch(s, st, dp, k + 1, j);
		if (left == 1 && right == 1) {
			return dp[i][j] = 1;
		}
	}
	return dp[i][j] = 0;
}
bool wordBreak(string &s, vector<string> &wordDict) {
	unordered_set<string> st;
	for (int i = 0; i < wordDict.size(); ++i) {
		st.insert(wordDict[i]);
	}
	vector<vector<int>>dp(s.size() + 1, vector<int>(s.size() + 1, -1));
	int flag = wordSearch(s, st, dp, 0, s.size() - 1);
	if (flag) {
		return true;
	}
	return false;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int num_strings;
		cin >> num_strings;
		vector<string> wordDict(num_strings);
		for (int i = 0; i < num_strings; ++i) {
			cin >> wordDict[i];
		}
		string s;
		cin >> s;
		cout << wordBreak(s, wordDict) << endl;
	}
	return 0;
}
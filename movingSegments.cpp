#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
bool check(int start, int end,map<int,pii> &books) {
	auto it = books.upper_bound(start);
	if (it == books.end() || it->second.first >= end) {
		books[end] = {start, 1};
		return true;
	}

	auto endIt = it;
	for (; endIt != books.end() && endIt->second.first < end; ++endIt)
		if (endIt->second.second >= 2) return false;

	if (start > it->second.first) {
		books[start] = {it->second.first, 1};
		it->second = {start, 1};
	}

	for (auto beginIt = it; beginIt != endIt; ++beginIt) {
		if (start < beginIt->second.first)
			books[beginIt->second.first] = {start, 1};
		books[min(beginIt->first, end)] = {beginIt->second.first, 2};
		start = beginIt->first;
	}

	endIt = prev(endIt);
	if (end > endIt->first)  books[end] = {endIt->first, 1};
	else if (end < endIt->first) books[endIt->first] = {end, 1};

	return true;
}
void solveQuestion() {
	map<int, vector<pii>> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		mp[z].push_back(make_pair(x, y));
	}
	bool flag = true;
	for (auto it : mp) {
		if ((it.second).size() > 2) {
			map<int, pii> books;
			for (pii x : it.second) {
				flag = flag && check(x.first, x.second + 1, books);
				if (flag) {
					cout << "NO" << '\n';
					return;
				}
			}
		}
	}
	cout << "YES" << '\n';
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> perm1(n);
	vector<int> perm2(n);
	unordered_map<int, int> idx2;
	for (int i = 0; i < n; i++) {
		cin >> perm1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> perm2[i];
		idx2[perm2[i]] = i;
	}
	int maxm = 0;
	unordered_map<int, int> shift_required;
	for (int i = 0; i < n; i++) {
		int element = perm1[i];
		int idx_present = idx2[perm1[i]];
		shift_required[(idx_present - i + n) % n]++;
	}
	for (auto it = shift_required.begin(); it != shift_required.end(); ++it) {
		maxm = max(maxm, it->second);
	}
	cout << maxm << endl;
	return 0;
}
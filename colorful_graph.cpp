#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
unordered_set<int> mp[100005];
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, e;
	cin >> n >> e;
	vector<int> colors(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> colors[i];
	}
	map<int, int> diversity;
	for(int i=1;i<=n;i++){
		diversity[colors[i]] = 0;
	}
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		if (colors[u] != colors[v]) {
			if (mp[colors[u]].count(colors[v]) == 0) {
				mp[colors[u]].insert(colors[v]);
				diversity[colors[u]]++;
			}
			if (mp[colors[v]].count(colors[u]) == 0) {
				mp[colors[v]].insert(colors[u]);
				diversity[colors[v]]++;
			}
		}
	}
	int ans = 100005, maxm = -1;
	for (auto it : diversity) {
		if (it.second > maxm) {
			ans = it.first;
			maxm = it.second;
		}
	}
	cout << ans << "\n";
	return 0;
}
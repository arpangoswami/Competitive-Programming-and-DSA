#include <bits/stdc++.h>
#define int long long
using namespace std;
int rows[4] = { -1, 0, 0, 1};
int cols[4] = {0, -1, 1, 0};
bool isSafe(int i, int j, int m, int n) {
	return ((i >= 0) && (j >= 0) && (i < m) && (j < n));
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int x, y;
		cin >> x >> y;
		if(m == 1 && n == 1){
			cout << x << "\n";
			continue;
		}
		vector<vector<int>> layout(n, vector<int>(m, 0));
		vector<vector<bool>> canPlace(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < m; j += 2) {
					canPlace[i][j] = true;
				}
			} else {
				for (int j = 1; j < m; j += 2) {
					canPlace[i][j] = true;
				}
			}
		}
		int ans = 0;
		int maxmPlace = min(y,x);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (canPlace[i][j]) {
					layout[i][j] = maxmPlace;
				}else{
					layout[i][j] = min(y - maxmPlace,x);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ans+=layout[i][j];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
void solveQ() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> prefRow(m, vector<int>(n));
	vector<vector<int>> prefCol(m, vector<int>(n));
	vector<vector<int>> suffRow(m, vector<int>(n));
	vector<vector<int>> suffCol(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				prefCol[i][j] = prefRow[i][j] = 1;
				if(i > 0){
					prefCol[i][j] += prefCol[i-1][j];
				}
				if(j > 0){
					prefRow[i][j] += prefRow[i][j-1];
				}
			} else {
				prefCol[i][j] = prefRow[i][j] = 0;
			}
		}
	}
	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if (arr[i][j] == 1) {
				suffCol[i][j] = suffRow[i][j] = 1;
				if(i < m-1){
					suffCol[i][j] += suffCol[i+1][j];
				}
				if(j < n-1){
					suffRow[i][j] += suffRow[i][j+1];
				}
			} else {
				suffCol[i][j] = suffRow[i][j] = 0;
			}
		}
	}
	int ans = 0;
	auto numL = [&](int dim1, int dim2) {
		if (min(dim1, dim2) < 2) {
			return;
		}
		//dim1 longer side:-
		ans += max(0LL,min(dim2-1LL,dim1/2 - 1));
		ans += max(0LL,min(dim1 - 1LL,dim2/2 - 1));
	};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1LL) {
				int up = prefCol[i][j];
				int down = suffCol[i][j];
				int left = prefRow[i][j];
				int right = suffRow[i][j];
				numL(up, left);
				numL(up, right);
				numL(down, left);
				numL(down, right);
				//cout<<"ans: "<<ans<<'\n';
			}
		}
	}
	// cout<<"prefRow: "<<'\n';
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<prefRow[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	// cout<<"prefCol: "<<'\n';
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<prefCol[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	// cout<<"sufffRow: "<<'\n';
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<suffRow[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	// cout<<"suffCol: "<<'\n';
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<suffCol[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	cout << ans << '\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		cout << "Case #" << t << ": ";
		solveQ();
	}
	return 0;
}
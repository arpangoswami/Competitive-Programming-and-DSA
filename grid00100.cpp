#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void solveQuestion() {
	int n, k;
	cin >> n >> k;
	vector<vector<char>> arr(n, vector<char>(n, '0'));
	int x = 0,y = 0;
	for (int _ = 0; _ < k; _ ++) {
		arr[x][y] = '1';
		x++;
		y = (y+1)%n;
		if(x == n){
			x = 0;
			y = (y+1)%n;
		}
	}
	int maxR = 0, minR = n, maxC = 0, minC = n;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (char c : arr[i]) {
			if (c == '1') {
				cnt++;
			}
		}
		maxR = max(maxR, cnt);
		minR = min(minR, cnt);
	}
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == '1') {
				cnt++;
			}
		}
		maxC = max(maxC, cnt);
		minC = min(minC, cnt);
	}
	cout << (maxR - minR) * (maxR - minR) + (maxC - minC) * (maxC - minC) << '\n';
	for (int i = 0; i < n; i++) {
		for (char c : arr[i]) {
			cout << c;
		}
		cout << '\n';
	}
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
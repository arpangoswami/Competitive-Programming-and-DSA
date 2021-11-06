/*
https://atcoder.jp/contests/abc185/tasks/abc185_f

F - Range Xor Query  / 
Time Limit: 3 sec / Memory Limit: 1024 MB

Score : 
600
 points

Problem Statement
We have an integer sequence A of length N.
You will process Q queries on this sequence. In the i-th query, given values 


Sample Input 2 
Copy
10 10
0 5 3 4 7 0 0 0 1 0
1 10 7
2 8 9
2 3 6
2 1 6
2 1 10
1 9 4
1 6 1
1 6 3
1 1 7
2 3 5
Sample Output 2 
Copy
1
0
5
3
0
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
void update(int idx, int val, vector<int> &BIT, int n) {
	for (int i = idx; i <= n; i += (i & (-i))) {
		BIT[i] ^= val;
	}
}
int query(int idx, vector<int> &BIT) {
	int ans = 0;
	for (int i = idx; i > 0; i -= (i & (-i))) {
		ans ^= BIT[i];
	}
	return ans;
}
void solveQuestion() {
	int n, q;
	cin >> n >> q;
	vector<int> arr(n + 1);
	vector<int> BIT(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i], BIT, n);
	}
	while (q--) {
		int type, left, right;
		cin >> type >> left >> right;
		if (type == 1) {
			update(left, right, BIT, n);
		} else {
			int leftVal = query(right, BIT);
			int rightVal = query(left - 1, BIT);
			cout << (leftVal ^ rightVal) << '\n';
		}
	}
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
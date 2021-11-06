#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
vector<pii> LbotLeft = {{0, 0}, {1, 0}, {1, 1}};
vector<pii> LtopRight = {{0, 0}, {0, 1}, {1, 1}};
vector<pii> LbotRight = {{0, 1}, {1, 1}, {1, 0}};
vector<pii> LtopLeft = {{0, 1}, {0, 0}, {1, 0}};
vector<vector<vector<pii>>> v = {{}, {LtopRight, LbotRight, LbotLeft}, {LbotLeft, LtopLeft, LbotRight}, {LtopRight, LtopLeft},
	{LtopRight, LtopLeft, LbotRight}, {LbotLeft, LtopLeft}, {LtopRight, LbotLeft}, {LbotRight},
	{LbotLeft, LtopRight, LtopLeft}, {LtopLeft, LbotRight}, {LbotRight, LtopRight}, {LbotLeft},
	{LbotRight, LbotLeft}, {LtopRight}, {LtopLeft}, {LbotLeft, LtopRight, LbotRight, LtopLeft}
};
void remainingOps(int **table, int row, int cols, vector<vector<int>> &oper) {
	for (int i = 0; i < row; i += 2) {
		int dig1 = table[i][0], dig2 = table[i][1], dig3 = table[i + 1][0], dig4 = table[i + 1][1];
		table[i][0] = 0;
		table[i + 1][0] = 0;
		table[i][1] = 0;
		table[i + 1][1] = 0;
		int idx = dig1 * 8 + dig2 * 4 + dig3 * 2 + dig4;
		for (int k = 0; k < v[idx].size(); k++) {
			vector<int> temp;
			for (pii x : v[idx][k]) {
				int ff = x.first, ss = x.second;
				temp.push_back(ff + i + 1);
				temp.push_back(ss + 1);
			}
			oper.push_back(temp);
		}
	}
}
void solveQuestion() {
	int n, m;
	cin >> n >> m;
	int **table = new int *[n]();
	for (int i = 0; i < n; i++) {
		table[i] = new int[m]();
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			table[i][j] = c - '0';
		}
	}
	int ops = 0;
	vector<vector<int>> oper;
	for (int j = m - 1; j >= 2; j--) {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				if (table[i][j] == 1) {
					table[i][j] ^= 1;
					table[i][j - 1] ^= 1;
					table[i - 1][j - 1] ^= 1;
					vector<int> temp;
					temp.push_back(i + 1);
					temp.push_back(j + 1);
					temp.push_back(i + 1);
					temp.push_back(j);
					temp.push_back(i);
					temp.push_back(j);
					oper.push_back(temp);
				}
			} else {
				if (table[i][j] == 1) {
					table[i][j] ^= 1;
					table[i + 1][j] ^= 1;
					table[i][j-1] ^= 1;
					vector<int> temp;
					temp.push_back(i + 1);
					temp.push_back(j + 1);
					temp.push_back(i + 2);
					temp.push_back(j + 1);
					temp.push_back(i + 1);
					temp.push_back(j);
					oper.push_back(temp);
				}
			}
		}
	}
	if (n % 2 == 1) {
		if (table[n - 1][0] == 1 && table[n - 1][1] == 1) {
			table[n - 1][0] ^= 1;
			table[n - 1][1] ^= 1;
			table[n - 2][1] ^= 1;
			vector<int> temp;
			temp.push_back(n);
			temp.push_back(1);
			temp.push_back(n);
			temp.push_back(2);
			temp.push_back(n - 1);
			temp.push_back(2);
			oper.push_back(temp);
		} else if (table[n - 1][0] == 1 && table[n - 1][1] == 0) {
			table[n - 1][0] ^= 1;
			table[n - 2][0] ^= 1;
			table[n - 2][1] ^= 1;
			vector<int> temp;
			temp.push_back(n);
			temp.push_back(1);
			temp.push_back(n - 1);
			temp.push_back(1);
			temp.push_back(n - 1);
			temp.push_back(2);
			oper.push_back(temp);
		} else if (table[n - 1][0] == 0 && table[n - 1][1] == 1) {
			table[n - 1][1] ^= 1;
			table[n - 2][0] ^= 1;
			table[n - 2][1] ^= 1;
			vector<int> temp;
			temp.push_back(n);
			temp.push_back(2);
			temp.push_back(n - 1);
			temp.push_back(1);
			temp.push_back(n - 1);
			temp.push_back(2);
			oper.push_back(temp);
		}
		remainingOps(table, n - 1, 2, oper);
	} else {
		remainingOps(table, n, 2, oper);
	}
	//cout<<"lmao"<<"\n";
	cout << oper.size() << "\n";
	for (auto v : oper) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		delete []table[i];
	}
	delete []table;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
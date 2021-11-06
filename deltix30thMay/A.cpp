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
bool oneNeighBour(int i, int n, string &s) {
	if (i < 0 || i >= n || s[i] == '1') {
		return false;
	}
	int nb = 0;
	if (i < (n - 1) && s[i + 1] == '1') {
		nb++;
	}
	if (i > 0 && s[i - 1] == '1') {
		nb++;
	}
	return (nb == 1);
}
void solveQuestion() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> ones;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			ones.push_back(i);
		}
	}
	while (k > 0 && ones.size() > 0) {
		for (int x : ones) {
			s[x] = '1';
		}
		vector<int> temp;
		for (int x : ones) {
			if (oneNeighBour(x - 1, n, s)) {
				temp.push_back(x - 1);
			}
			if (oneNeighBour(x + 1, n, s)) {
				temp.push_back(x + 1);
			}
		}
		temp.swap(ones);
		k--;
	}
	for (int x : ones) {
		s[x] = '1';
	}
	cout << s << "\n";

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
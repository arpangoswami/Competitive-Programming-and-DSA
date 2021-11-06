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
	string s;
	cin >> s;
	int dist = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			dist += 2;
		} else {
			dist++;
		}
	}
	vi arr(k);
	for (int &i : arr) {
		cin >> i;
	}
	for (int i = 0; i < k; i++) {
		int v = arr[i];
		v--;
		int original = s[v] - '0';
		int newNum = 1 - original;
		if (v > 0) {
			if (s[v] == s[v - 1]) {
				dist--;
			} else {
				dist++;
			}
		}
		if (v < (n - 1)) {
			if (s[v] == s[v + 1]) {
				dist--;
			} else {
				dist++;
			}
		}
		s[v] = '0' + newNum;
		cout << dist << "\n";
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
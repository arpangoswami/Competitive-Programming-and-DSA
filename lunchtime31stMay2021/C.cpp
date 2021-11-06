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
const int sz = 1e7;
int sieve[sz + 1];
void pre() {
	for (int i = 3; i <= sz; i += 2) {
		sieve[i] = 1;
	}
	for (int i = 3; i * i <= sz; i += 2) {
		if (sieve[i]) {
			for (int j = i * i; j <= sz; j += i) {
				sieve[j] = 0;
			}
		}
	}
	for (int i = 1; i <= sz; i++) {
		sieve[i] += sieve[i - 1];
	}
}
void solveQuestion() {
	int n;
	cin >> n;
	int primes = sieve[n] - sieve[n / 2];
	cout << 1 + primes << "\n";
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int test = 1;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
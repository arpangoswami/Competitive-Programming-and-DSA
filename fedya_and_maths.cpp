#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
ll power(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll smallAns = power(a, b / 2);
	if (b & 1) {
		return smallAns * smallAns * a;
	}
	return smallAns * smallAns;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n;
	if (s.size() == 1) {
		n = s[0] - 48;
	} else {
		int x = s.size();
		n = (s[x - 2] - 48) * 10 + (s[x - 1] - 48);
	}
	int a = 1;
	int b, c, d;
	if (n % 4 == 0) {
		b = 6;
		c = 1;
		d = 6;
	} else if (n % 4 == 1) {
		b = 2;
		c = 3;
		d = 4;
	} else if (n % 4 == 2) {
		b = 4;
		c = 9;
		d = 6;
	} else if (n % 4 == 3) {
		b = 8;
		c = 7;
		d = 4;
	}
	cout << (a + b + c + d) % 5 << endl;
	return 0;
}
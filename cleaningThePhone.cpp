#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
bool check(vi &ones, vi &twos, int M, int N, int m, int pts) {
	auto it = lower_bound(twos.begin(), twos.end(), m);
	if (it != twos.end()) {
		int pos = it - twos.begin();
		if ((pos + 1) * 2 <= pts) {
			return true;
		}
	}
	int sz = min(pts,M);
	for (int i = 0; i < sz; i++) {
		if(ones[i] >= m){
			return true;
		}
		auto it = lower_bound(twos.begin(), twos.end(), m - ones[i]);
		if (it != twos.end()) {
			int pos = it - twos.begin();
			if ((pos + 1) * 2 + (i+1)<= pts) {
				return true;
			}
		}
	}
	return false;
}
void solveQuestion() {
	int n, m;
	cin >> n >> m;
	vi mem(n);
	vi conv(n);
	vi ones;
	vi twos;
	int sm = 0, cv = 0;
	for (int &i : mem) {
		cin >> i;
		sm += i;
	}
	for (int &i : conv) {
		cin >> i;
		cv += i;
	}
	if (sm < m) {
		cout << -1 << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (conv[i] == 1) {
			ones.push_back(mem[i]);
		} else {
			twos.push_back(mem[i]);
		}
	}
	sort(ones.begin(), ones.end(), greater<int>());
	sort(twos.begin(), twos.end(), greater<int>());
	int ans = cv, low = 1, high = cv, M = ones.size(), N = twos.size();
	for (int i = 1; i < M; i++) {
		ones[i] += ones[i - 1];
	}
	for (int i = 1; i < N; i++) {
		twos[i] += twos[i - 1];
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(ones, twos, M, N, m, mid)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}
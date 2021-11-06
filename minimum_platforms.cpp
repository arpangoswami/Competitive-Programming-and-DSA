#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<pii> trains(n);
		for (int i = 0; i < n; i++) {
			cin >> trains[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> trains[i].second;
		}
		int plat = 1;
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(trains[0].second);
		for (int i = 1; i < n; i++) {
			if (trains[i].first <= pq.top()) {
				pq.push(trains[i].second);
				if(pq.size() > plat){
					plat = pq.size();
				}
			} else {
				while (!pq.empty() && pq.top() < trains[i].first) {
					pq.pop();
				}
				pq.push(trains[i].second);
			}
		}
		cout << plat << endl;
	}
	return 0;
}
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
		vector<int> arr(n);
		vector<int> mp(1001, 0);
		unordered_set<int> st;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mp[arr[i]]++;
			st.insert(arr[i]);
		}
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}
		bool flag = true;
		int last = arr[0];
		unordered_set<int> visited;
		visited.insert(arr[0]);
		for (int i = 1; i < n; i++) {
			if (arr[i] != arr[i - 1]) {
				if (visited.count(arr[i]) != 0) {
					flag = false;
					break;
				}	
			}
			visited.insert(arr[i]);
		}
		//cout<<flag<<endl;
		if (flag) {
			for (int i = 1; i <= 1000; i++) {
				if (mp[i] == 0) {
					continue;
				}
				for (int x : st) {
					if (mp[i] == mp[x] && i!=x) {
						//cout<<i<<" "<<x<<endl;
						flag = false;
						break;
					}
				}
				if (!flag) {
					break;
				}
			}
		}
		// cout<<"flag: "<<flag<<endl;
		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
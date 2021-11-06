#include <bits/stdc++.h>
#define int long long
using namespace std;
int diff(string a,string b){
	int cnt = 0;
	for(int i=0;i<a.size();i++){
		if(a[i] != b[i]){
			cnt++;
		}
	}
	return cnt;
}
string oneDiff(vector<string> &arr) {
	int n = arr.size(), m = arr[0].size();
	string temp = arr[0];
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (diff(temp, arr[i]) > 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		return temp;
	}
	for (int i = 0; i < m; i++) {
		set<char> st;
		for (int j = 0; j < n; j++) {
			st.insert(arr[j][i]);
		}
		for (char c : st) {
			string temp2 = arr[0];
			temp2[i] = c;
			bool flag = true;
			for (int k = 0; k < n; k++) {
				if (diff(temp2, arr[k]) > 1) {
					flag = false;
					break;
				}
			}
			if(flag){
				return temp2;
			}
		}
	}
	return "-1";
}
void solveQuestion() {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (m == 1) {
		cout << "a" << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j) {
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < m; k++) {
				if (arr[i][k] != arr[j][k]) {
					cnt++;
					if (cnt == 3) {
						cout << -1 << '\n';
						return;
					}
				}
			}
		}
	}
	string ans = oneDiff(arr);
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
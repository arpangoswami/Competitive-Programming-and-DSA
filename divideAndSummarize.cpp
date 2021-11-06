/*
1
5 5
3 1 3 1 3
1
2
3
9
11
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
vector<int> arr, prefixSum;
inline int calSum(int i, int j) {
	return (i == 0) ? prefixSum[j] : prefixSum[j] - prefixSum[i - 1];
}
unordered_set<int> st;
void checkSum(int i, int j) {
	if (i > j) {
		return;
	}
	int sm = calSum(i, j);
	st.insert(sm);
	if(arr[i] == arr[j]){
		return;
	}
	int mid = (arr[i] + arr[j]) / 2;
	vector<int>::iterator it = upper_bound(arr.begin() + i, arr.begin() + j, mid);
	--it;
	int k = it - arr.begin();
	checkSum(i, k);
	checkSum(k + 1, j);
}
void solveQuestion() {
	int n, q;
	cin >> n >> q;
	st.clear();
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	prefixSum.resize(n);
	prefixSum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	}
	checkSum(0,n-1);
	for (int i = 0; i < q; i++) {
		int sum;
		cin >> sum;
		if (st.count(sum)) {
			cout << "Yes" << '\n';
			continue;
		}
		else{
			cout<<"No"<<'\n';
		}
	}
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
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int helper(vector<int> &arr,int n) {
	vector<int> len(n);
	int idx = 0;
	int curr = 1;
	while (idx < n) {
		int val = arr[idx];
		int i = idx;
		while (i < n && arr[i] == val) {
			len[i] = curr;
			i++;
		}
		idx = i;
		curr++;
	}
	int maxm = 1;
	for (int x : len) {
		maxm = max(maxm, x);
	}
	return maxm;
}
void solveQuestion() {
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = helper(arr,n);
	while (q--) {
		int index, value;
		cin >> index >> value;
		index--;
		int prev = arr[index];
		int newVal = value;
		if(index > 0 && prev!=arr[index-1]){
			ans--;
		}
		if(index < (n-1) && prev!=arr[index+1]){
			ans--;
		}
		if(index > 0 && newVal!=arr[index-1]){
			ans++;
		}
		if(index < (n-1) && newVal!=arr[index+1]){
			ans++;
		}
		cout<<ans<<"\n";
		arr[index] = value;
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
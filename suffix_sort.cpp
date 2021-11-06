#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
bool isSorted(vector<int> &arr) {
	for (int k = 1; k < arr.size(); k++) {
		if (arr[k] < arr[k - 1]) {
			return false;
		}
	}
	return true;
}
bool cyclicSorted(vector<int>& nums) {
	int n = nums.size();
	vector<int> copy;
	copy.push_back(nums[0]);
	int i;
	for (i = 1; i < n; i++) {
		if (nums[i] >= nums[i - 1]) {
			copy.push_back(nums[i]);
		} else {
			break;
		}
	}
	if (copy.size() == n) {
		return true;
	}
	i++;
	for (; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			return false;
		}
	}
	return nums.back() <= copy[0];
}
void solveQuestion() {
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (isSorted(arr)) {
		cout << "YES" << '\n';
		cout << 0 << '\n';
		return;
	}
	if (cyclicSorted(arr)) {
		cout << "YES" << '\n';
		cout << 1 << '\n';
		return;
	}
	cout << "NO" << '\n';
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
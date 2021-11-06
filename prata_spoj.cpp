/*PRATA - Roti Prata
no tags
IEEE is having its AGM next week and the president wants to serve cheese
prata after the meeting. The subcommittee members are asked to go to food
connection and get P(P <= 1000) pratas packed for the function.
The stall has L cooks(L <= 50) and each cook has a rank R(1 <= R <= 8).
	A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes,
	1 more prata in 3R minutes and so on(he can only cook a complete prata)
	( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next
	  6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only
	  3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the
			minimum time to get the order done. Please write a program to help him out.



			Input
		The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

					Output
					Print an integer which tells the number of minutes needed to get the order done.



					Example
					Input:

3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1
Output:
12
36
1*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(int time, vector<int> &arr, int n, int req) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int prep = (-arr[i] + floor(sqrt(arr[i] * arr[i] + 8 * arr[i] * time))) / (2 * arr[i]);
		cnt += prep;
	}
	return cnt >= req;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int paratha;
		cin >> paratha;
		int n;
		cin >> n;
		vector<int> arr(n);
		int minm = 8;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			minm = min(arr[i], minm);
		}
		int low = 0, high = minm * ((paratha * (paratha + 1)) / 2);
		int ans = high;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (check(mid, arr, n, paratha)) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
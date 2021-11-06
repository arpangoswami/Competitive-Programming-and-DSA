/*
Alternating Subsequences

You are given an array of N non-negative integers: A1, A2, ..., AN. An alternating subsequence is a subsequence in which the indices of any two consecutive elements differ by exactly two in the original array. That is, if Ai1, Ai2, ..., Aik is some subsequence, then for it to be an alternating subsequence, (i2 - i1 = 2), (i3 - i2 = 2), and so on should all hold true. Among all alternating subsequences, find the one which has maximum sum of elements, and output that sum.

Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains an integer N denoting the number of elements in the array.

The second line contains N space-separated integers A1, A2, ..., AN denoting the array A.

Output
For each test case, output a single line containing the answer.

Note
A subsequence with only a single integer is also an alternating subsequence.
Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ Ai ≤ 105
Scoring Infomation
20% score for N ≤ 100
30% score for N ≤ 1000
50% score for N ≤ 105
Example
Input:
1
3
1 2 5

Output:
6
Explanation
Example case 1.
For the given array [1, 2, 5], there are 7 non-empty subsequences out of which there are 4 alternating subsequences. These will be {[1], [2], [5], [1, 5]}. The alternating subsequence [1, 5] will have the largest sum i.e 6.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void solveQuestion() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i += 2) {
		sum1 += arr[i];
	}
	for (int i = 1; i < n; i += 2) {
		sum2 += arr[i];
	}
	cout << max(sum1, sum2) << "\n";
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
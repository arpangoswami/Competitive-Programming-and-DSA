/*
Dole Out Cadbury
Problem Description
You are a teacher in reputed school. During Celebration Day you were assigned a task to distribute Cadbury such that maximum children get the chocolate. You have a box full of Cadbury with different width and height. You can only distribute largest square shape Cadbury. So if you have a Cadbury of length 10 and width 5, then you need to break Cadbury in 5X5 square and distribute to first child and then remaining 5X5 to next in queue

Constraints
0<P<Q<1501

0<R<S<1501

Input Format
First line contains an integer P that denotes minimum length of Cadbury in the box

Second line contains an integer Q that denotes maximum length of Cadbury in the box

Third line contains an integer R that denotes minimum width of Cadbury in the box

Fourth line contains an integer S that denotes maximum width of Cadbury in the box

Output
Print total number of children who will get chocolate.

Timeout
1

Explanation
Example 1

Input

5

7

3

4

Output

24

Explanation

Length is in between 5 to 7 and width is in between 3 to 4.

So we have 5X3,5X4,6X3,6X4,7X3,7X4 type of Cadbury in the box.

If we take 5X3 :

First, we can give 3X3 square Cadbury to 1st child .Then we are left with 3X2. Now largest square is 2X2 which will be given to next child. Next, we are left with two  1X1 part of Cadbury which will be given to another two children.

And so on
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
int solve(int len, int wid) {
	int min_size = min(len, wid), max_size = max(len, wid);
	int cnt = 0;
	while (true) {
		int temp = min_size;
		min_size = min(min_size, max_size);
		max_size = max(temp, max_size);
		cnt++;
		if (max_size == min_size) {
			break;
		}
		max_size -= min_size;
	}
	return cnt;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int min_len, max_len, min_wid, max_wid;
	cin >> min_len >> max_len >> min_wid >> max_wid;
	int ans = 0;
	for (int i = min_len ; i <= max_len; i++) {
		for (int j = min_wid; j <= max_wid; j++) {
			ans += solve(i, j);
		}
	}
	cout << ans;
	return 0;
}
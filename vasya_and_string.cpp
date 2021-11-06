/*
https://codeforces.com/problemset/problem/676/C

C. Vasya and String
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only. Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.

Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?

Input
The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) — the length of the string and the maximum number of characters to change.

The second line contains the string, consisting of letters 'a' and 'b' only.

Output
Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.

Examples
inputCopy
4 2
abba
outputCopy
4
inputCopy
8 1
aabaabaa
outputCopy
5
Note
In the first sample, Vasya can obtain both strings "aaaa" and "bbbb".

In the second sample, the optimal answer is obtained with the string "aaaaabaa" or with the string "aabaaaaa".
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int max_length = 1;
	vector<int> a_prefix(n, 0);
	vector<int> b_prefix(n, 0);
	if (s[0] == 'a') {
		a_prefix[0] = 1;
	}
	if (s[0] == 'b') {
		b_prefix[0] = 1;
	}
	for (int i = 1; i < n; i++) {
		a_prefix[i] = a_prefix[i - 1];
		b_prefix[i] = b_prefix[i - 1];
		if (s[i] == 'a') {
			a_prefix[i]++;
		} else {
			b_prefix[i]++;
		}
	}
	if (a_prefix.back() <= k || b_prefix.back() <= k) {
		cout << n << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				int val = b_prefix[i];
				auto itr = upper_bound(b_prefix.begin(), b_prefix.end(), val + k);
				itr = prev(itr);
				int pos = itr - b_prefix.begin();
				int length = pos - i + 1;
				max_length = max(max_length, length);
			} else {
				int val = a_prefix[i];
				auto itr = upper_bound(a_prefix.begin(), a_prefix.end(), val + k);
				itr = prev(itr);
				int pos = itr - a_prefix.begin();
				int length = pos - i + 1;
				max_length = max(max_length, length);
			}
		}
		cout << max_length << endl;
	}
	return 0;
}
/*
Swayamvar
Problem Description
A ceremony where a Bride chooses her Groom from an array of eligible bachelors is called Swayamvar. But this is a Swayamvar with difference. An array of Bride-to-be will choose from an array of Groom-to-be.

The arrangement at this Swayamvar is as follows

· Brides-to-be are organized such that the most eligible bachelorette will get first chance to choose her Groom. Only then, the next most eligible bachelorette will get a chance to choose her Groom

· If the initial most eligible bachelorette does not get a Groom of her choice, none of the Brides-to-be have any chance at all to get married. So unless a senior bachelorette is out of the “queue”, the junior bachelorette does not get a chance to select her Groom-to-be

· Inital state of Grooms-to-be is such that most eligible bachelor is at the head of the “queue”. The next most eligible bachelor is next in the queue. So on and so forth.

· Now everything hinges on the choice of the bachelorette. The most eligible bachelorette will now meet the most eligible bachelor.

· If bachelorette selects the bachelor, both, the bachelorette and the bachelor are now Bride and Groom respectively and will no longer be a part of the Swayamvar activity. Now, the next most eligible bachelorette will get a chance to choose her Groom. Her first option is the next most eligible bachelor (relative to initial state)

· If the most eligible bachelorette passes the most eligible bachelor, the most eligible bachelor now moves to the end of the queue. The next most eligible bachelor is now considered by the most eligible bachelorette. Selection or Passing over will have the same consequences as explained earlier.

· If most eligible bachelorette reaches the end of bachelor queue, then the Swayamvar is over. Nobody can get married.

· Given a mix of Selection or Passing over, different pairs will get formed.

The selection criteria is as follows

1. Each person either drinks rum or mojito. Bride will choose groom only if he drinks the same drink as her.

Note : There are equal number of brides and grooms for the swayamvar.

Tyrion as the hand of the king wants to know how many pairs will be left unmatched. Can you help Tyrion?

Constraints
1<= N <= 10^4

Input Format
First line contains one integer N, which denotes the number of brides and grooms taking part in the swayamvar. Second line contains a string in lowercase, of length N containing initial state of brides-to-be. Third line contains a string in lowercase, of length N containing initial state of grooms-to-be. Each string contains only lowercase 'r' and 'm' stating person at that index drinks "rum"(for 'r') or mojito(for 'm').

Output
Output a single integer denoting the number of pairs left unmatched.

Timeout
1

Explanation
Example 1

Input

4

rrmm mrmr

Output

0

Explanation

The bride at first place will only marry groom who drinks rum. So the groom at first place will join the end of the queue. Updated groom's queue is "rmrm".

Now the bride at first place will marry the groom at first place. Updated bride's queue is "rmm" and groom's queue is "mrm".

The process continues and at last there are no pairs left. So answer is 0.

Example 2

Input

4 rmrm mmmr

Output

2

Explanation

Following the above process 2 pairs will be left unmatched. Remember that bride will not move until she gets a groom of her choice.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int lastCntIdx(string &brides, int diff, int n, char c) {
	int cnt = 0;
	int idx = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (brides[i] == c) {
			cnt++;
		}
		if (cnt == diff) {
			idx = i;
			break;
		}
	}
	return n - idx;
}
typedef vector<int> vi;
typedef pair<int, int> pii;
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string brides, grooms;
	cin >> brides >> grooms;
	int rum_g = 0, moj_g = 0, rum_b = 0, moj_b = 0;
	for (int i = 0; i < n; i++) {
		if (brides[i] == 'r') {
			rum_b++;
		} else {
			moj_b++;
		}
		if (grooms[i] == 'r') {
			rum_g++;
		} else {
			moj_g++;
		}
	}
	if (rum_g == rum_b) {
		cout << 0;
	} else {
		if (rum_b > rum_g) {
			int diff = rum_b - rum_g;
			cout << lastCntIdx(brides, diff, n, 'r');
		} else {
			int diff = moj_b - moj_g;
			cout << lastCntIdx(brides, diff, n, 'm');
		}
	}
	return 0;
}
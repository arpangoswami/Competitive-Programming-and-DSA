/*
FISHER - Fishmonger
no tags 
A FishmongerA fishmonger wants to bring his goods from the port to the market. On his route he has to traverse an area with many tiny city states. Of course he has to pay a toll at each border.

Because he is a good business man, he wants to choose the route in such a way that he has to pay as little money for tolls as possible. On the other hand, he has to be at the market within a certain time, otherwise his fish start to smell.

Input
The first line contains the number of states n and available time t. The first state is the port, the last state is the market. After this line there are n lines with n numbers each, specifying for each state the travel time to the i-th state. This table is terminated with an empty line. The table of the tolls follows in the same format.

n is at least 3 and at most 50. The time available is less than 1000. All numbers are integers.

There are many test cases separated by an empty line. Input terminates with number of states and time equal 0 0.

Output
For each test case your program should print on one line the total amount of tolls followed by the actual travelling time.

Example
Sample input:
4 7
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0

0 0

Sample output:
6 6
This corresponds to the following situation, the connections are labeled with (time, toll):
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc, char const* argv[]) {
	while (true) {
		int N, T;
		cin >> N >> T;
		if (N == 0 && T == 0) {
			break;
		}
		int cost[51][51];
		int inpTime[51][51];
		int dp[51][1001];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> inpTime[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cost[i][j];
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			dp[i][0] = 1e12;
		}
		int tm = -1;
		for (int k = 1; k <= T; k++) {
			for (int i = 0; i < N; i++) { // destination city
				dp[i][k] = dp[i][k - 1];
				for (int j = 0; j < N; j++) { // source city
					if (k < inpTime[j][i]) {
						continue;
					}
					dp[i][k] = min(dp[i][k], dp[j][k - inpTime[j][i]] + cost[j][i]);
				}
			}
			if (dp[N - 1][k] != dp[N - 1][k - 1]) {
				tm = k;
			}
		}
		cout << dp[N - 1][tm] << " " << tm << '\n';

	}
	return 0;
}
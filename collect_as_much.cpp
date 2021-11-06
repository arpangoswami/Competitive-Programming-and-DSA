/*
Collect as much as you can
Problem
Submissions
Leaderboard
Discussions
A frog sees a series of N stones placed in a row. Stepping on the ith stone adds a score of A[i] to the frogs total score. The frog can make a jump of length exactly K, that is if he is at ith stone, he can jump to i+Kth stone. The frog can start and end at any stone but has to step on atleast one stone.

Calculate the maximum possible score of the frog.

Input Format

N denoting number of stones and K denoting jump length

N number from A[0] to A[N-1]

Constraints

1<= K <= N <=2 * 10^5

-10^12 <= A[i] <= 10^12

Output Format

The maximum score that can be achieved by the frog.

Sample Input 0

5 3
1 1 1 2 3
Sample Output 0

4
Explanation 0

The frog will start at stone 2, take a 3 step jump to stone 5 and collect 1+3 = 4 points.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n,k;
		cin >> n >>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		vector<int> dp(n);
		for(int i=0;i<n;i++){
			dp[i] = arr[i];
		}
		for(int i=k;i<n;i++){
			dp[i] = max(dp[i],dp[i-k] + arr[i]);
		}
		int maxm = LONG_MIN;
		for(int i=0;i<n;i++){
			maxm = max(dp[i],maxm);
		}
		cout << maxm <<'\n';
	}
	return 0;
}
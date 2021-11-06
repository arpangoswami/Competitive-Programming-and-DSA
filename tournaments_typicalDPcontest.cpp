/*
	https://atcoder.jp/contests/tdpc/tasks/tdpc_tournament
	C - Tournaments 
Run time limit: 2 sec / Memory limit: 256 MB

Problem Statement
2
K
 There are tournaments where people participate. In this tournament, the match will be played in the following format:
In the first round, 1 and 2, 3 and 4 、... There is a game to be played.
In the second round ( 1 and 2 winners) and (3 and 4 winners), (5 and 6 winners) and (7 and 8 winners), ... There is a game to be played.
In the third round (winners of 1 and 2) and (winners of 3 and 4) and (winners of 5 and 6) and (winners of 7 and 8), (winners of 9 and 10) and (winners of 11 and 12) and (winners of 13 and 14) and (winners of 15 and 16), ... There is a game to be played.
Do so until the first round as follows.
K
The winner will be determined after the end of the first round. When a person's Elo Rating is, ask for a person's chances of winning.
However, if Elo Rating person P and Elo Rating person Q play against each other, the probability that person P will win is independent, and the win or loss of different matches is
independent. 
person 1 -> rating A
person 2 -> rating B
probability that 1 wins a match against 2 is (1/(1 + 10 ^ ((B-A)/400)))
probability that 2 wins a match against 1 is (1/(1 + 10 ^ ((A-B)/400)))

Sample Input 1
1
2200
2600
Sample Output 1
0.090909091
0.909090909
Sample Input 2
3
2000
2500
2300
2700
2100
2400
2600
2200
Sample Output 2
0.000086893
0.122042976
0.005522752
0.493464665
0.000651695
0.053982389
0.321828438
0.002420190
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	int N = (1 << n);
	vector<int> arr(N);
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	vector<vector<double>>dp(n+1,vector<double>(N,0.00));
	for(int i=0;i<N;i++){
		dp[0][i] = 1.00;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<N;j++){
			int size = (1 << i);
			int group = j/size;
			int smallSize = (1 << (i-1));
			int start = group * size;
			for(int k=start;k<(start+size);k++){
				if((k/smallSize) == (j/smallSize)){
					continue;
				}
				double prob = dp[i-1][j] * dp[i-1][k] * 1.00/(1.00 + pow(10.00,(arr[k]-arr[j])/400.00));
				dp[i][j] += prob;
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<fixed<<setprecision(9)<<dp[n][i]<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}
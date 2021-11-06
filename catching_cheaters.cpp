/*D. Catching Cheaters
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two strings A and B representing essays of two students who are suspected cheaters. For any two strings C, D we define their similarity score S(C,D) as 4⋅LCS(C,D)−|C|−|D|, where LCS(C,D) denotes the length of the Longest Common Subsequence of strings C and D.

You believe that only some part of the essays could have been copied, therefore you're interested in their substrings.

Calculate the maximal similarity score over all pairs of substrings. More formally, output maximal S(C,D) over all pairs (C,D), where C is some substring of A, and D is some substring of B.

If X is a string, |X| denotes its length.

A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

A string a is a subsequence of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters.

Pay attention to the difference between the substring and subsequence, as they both appear in the problem statement.

You may wish to read the Wikipedia page about the Longest Common Subsequence problem.

Input
The first line contains two positive integers n and m (1≤n,m≤5000) — lengths of the two strings A and B.

The second line contains a string consisting of n lowercase Latin letters — string A.

The third line contains a string consisting of m lowercase Latin letters — string B.

Output
Output maximal S(C,D) over all pairs (C,D), where C is some substring of A, and D is some substring of B.

Examples
inputCopy
4 5
abba
babab
outputCopy
5
inputCopy
8 10
bbbbabab
bbbabaaaaa
outputCopy
12
inputCopy
7 7
uiibwws
qhtkxcn
outputCopy
0
Note
For the first case:

abb from the first string and abab from the second string have LCS equal to abb.

The result is S(abb,abab)=(4⋅|abb|) - |abb| - |abab| = 4⋅3−3−4=5.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	string a,b;
	cin >> a >> b;
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = 2 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]) - 1,0LL);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			ans = max(ans,dp[i][j]);
		}
	}	
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
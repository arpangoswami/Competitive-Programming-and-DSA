/*DSUBSEQ - Distinct Subsequences
#dynamic-programming
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.

Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences.

Example
Input:
3
AAA
ABCDEFG
CODECRAFT


Output:
4
128
496
Constraints and Limits
T ≤ 100, length(S) ≤ 100000
All input strings shall contain only uppercase letters.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll mod = 1e9L+7;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int n = s.size();
		vector<int> lastAppeared(26,-1);
		vector<ll> dp(n+1);
		dp[n] = 1;
		for(int i=n-1;i>=0;i--){
			ll x = dp[i+1];
			ll y = 0;
			if(lastAppeared[s[i] -65]!=-1){
				int idx = lastAppeared[s[i] - 65];
				y = dp[idx+1];
			}
			dp[i] = ((2*x - y)+mod)%mod;
			lastAppeared[s[i] - 65] = i;
		}
		cout<<dp[0]<<endl;
	}
	return 0;
}
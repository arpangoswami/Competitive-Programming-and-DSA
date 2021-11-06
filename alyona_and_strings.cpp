/*
https://codeforces.com/contest/682/problem/D
D. Alyona and Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
After returned from forest, Alyona started reading a book. She noticed strings s and t, lengths of which are n and m respectively. As usual, reading bored Alyona and she decided to pay her attention to strings s and t, which she considered very similar.

Alyona has her favourite positive integer k and because she is too small, k does not exceed 10. The girl wants now to choose k disjoint non-empty substrings of string s such that these strings appear as disjoint substrings of string t and in the same order as they do in string s. She is also interested in that their length is maximum possible among all variants.

Formally, Alyona wants to find a sequence of k non-empty strings p1, p2, p3, ..., pk satisfying following conditions:

s can be represented as concatenation a1p1a2p2... akpkak + 1, where a1, a2, ..., ak + 1 is a sequence of arbitrary strings (some of them may be possibly empty);
t can be represented as concatenation b1p1b2p2... bkpkbk + 1, where b1, b2, ..., bk + 1 is a sequence of arbitrary strings (some of them may be possibly empty);
sum of the lengths of strings in sequence is maximum possible.
Please help Alyona solve this complicated problem and find at least the sum of the lengths of the strings in a desired sequence.

A substring of a string is a subsequence of consecutive characters of the string.

Input
In the first line of the input three integers n, m, k (1 ≤ n, m ≤ 1000, 1 ≤ k ≤ 10) are given — the length of the string s, the length of the string t and Alyona's favourite number respectively.

The second line of the input contains string s, consisting of lowercase English letters.

The third line of the input contains string t, consisting of lowercase English letters.

Output
In the only line print the only non-negative integer — the sum of the lengths of the strings in a desired sequence.

It is guaranteed, that at least one desired sequence exists.

Examples
inputCopy
3 2 2
abc
ab
outputCopy
2
inputCopy
9 12 4
bbaaababb
abbbabbaaaba
outputCopy
7
Note
The following image describes the answer for the second sample case:



*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[1005][1005][11][2];
int maxSubseqWithKsubstring(string &a,string &b,int n,int m,int k,int state){
	if(k<0){
		return INT_MIN;
	}
	if(dp[n][m][k][state]!=-1){
		return dp[n][m][k][state];
	}
	if(n <= 0 || m <= 0){
		if(k == 0)
			return 0;
		return INT_MIN;
	}
	int &ans = dp[n][m][k][state];
	int ans1 = maxSubseqWithKsubstring(a,b,n-1,m,k,0);
	int ans2 = maxSubseqWithKsubstring(a,b,n,m-1,k,0);
	if(state == 1){
		if(a[n-1] == b[m-1]){
			int ans3 = 1 + maxSubseqWithKsubstring(a,b,n-1,m-1,k,1);
			int ans4 = 1 + maxSubseqWithKsubstring(a,b,n-1,m-1,k-1,1);
			return ans = max({ans1,ans2,ans3,ans4});
		}else{
			return ans = max(ans1,ans2);
		}
	}else{
		if(a[n-1] == b[m-1]){
			int ans3 = 1 + maxSubseqWithKsubstring(a,b,n-1,m-1,k-1,1);
			return ans = max({ans1,ans2,ans3});
		}else{
			return ans = max(ans1,ans2);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	string a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	cout<<maxSubseqWithKsubstring(a,b,n,m,k,0)<<endl;
	return 0;
}
/*
PERMUT1 - Permutations
#dynamic-programming
Let A = [a1,a2,...,an] be a permutation of integers 1,2,...,n. A pair of indices (i,j), 1<=i<=j<=n, is an inversion of the permutation A if ai>aj. We are given integers n>0 and k>=0. What is the number of n-element permutations containing exactly k inversions?

For instance, the number of 4-element permutations with exactly 1 inversion equals 3.

Task
Write a program which for each data set from a sequence of several data sets:

reads integers n and k from input,
computes the number of n-element permutations with exactly k inversions,
writes the result to output.
Input
The first line of the input file contains one integer d, 1<=d<=10, which is the number of data sets. The data sets follow. Each data set occupies one line of the input file and contains two integers n (1<=n<=12) and k (0<=k<=98) separated by a single space.

Output
The i-th line of the output file should contain one integer - the number of n-element permutations with exactly k inversions.

Example
Sample input:
1 
4 1 

Sample output:
3 
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[100][100];
int solve(int n,int k){
	if(dp[n][k] != -1){
		return dp[n][k];
	}
	if(n == 0){
		return dp[n][k] = 0;
	}
	if(k == 0){
		return dp[n][k] = 1;
	}
	int ans = 0;
	for(int i=0;i<n && k-i>=0;i++){
		ans += solve(n-1,k-i);
	}
	return dp[n][k] = ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin >> n >> k;
		memset(dp,-1,sizeof(dp));
		cout<<solve(n,k)<<"\n";
	}
	return 0;
}
/*
https://www.codechef.com/problems/XORSUB
You have an array of integers A1, A2, ..., AN. The function F(P), where P is a subset of A, is defined as the XOR (represented by the symbol ⊕) of all the integers present in the subset. If P is empty, then F(P)=0.

Given an integer K, what is the maximum value of K ⊕ F(P), over all possible subsets P of A?

Input
The first line contains T, the number of test cases. Each test case consists of N and K in one line, followed by the array A in the next line.

Output
For each test case, print the required answer in one line.

Constraints
1 ≤ T ≤ 10
1 ≤ K, Ai ≤ 1000
Subtask 1 (30 points):1 ≤ N ≤ 20
Subtask 2 (70 points):1 ≤ N ≤ 1000
Example
Input:
1
3 4
1 2 3

Output:
7
Explanation
Considering all subsets:
F({}) = 0 ⇒ 4 ⊕ 0 = 4
F({1}) = 1 ⇒ 4 ⊕ 1 = 5
F({1,2}) = 3 ⇒ 4 ⊕ 3 = 7
F({1,3}) = 2 ⇒ 4 ⊕ 2 = 6
F({1,2,3}) = 0 ⇒ 4 ⊕ 0 = 4
F({2}) = 2 ⇒ 4 ⊕ 2 = 6
F({2,3}) = 1 ⇒ 4 ⊕ 1 = 5
F({3}) = 3 ⇒ 4 ⊕ 3 = 7
Therefore, the answer is 7.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[1025][1001];
int maxXorSub(vector<int> &arr,int idx,int xorTillNow,int n){
	if(idx == n){
		return xorTillNow;
	}
	if(dp[xorTillNow][idx]!=-1){
		return dp[xorTillNow][idx];
	}
	return dp[xorTillNow][idx] = max(maxXorSub(arr,idx+1,xorTillNow^arr[idx],n),maxXorSub(arr,idx+1,xorTillNow,n));
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		memset(dp,-1,sizeof(dp));
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<maxXorSub(arr,0,k,n)<<endl;
	}
	return 0;
}
/*
C. The Sports Festival
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The student council is preparing for the relay race at the sports festival.

The council consists of n members. They will run one after the other in the race, the speed of member i is si.
The discrepancy di of the i-th stage is the difference between the maximum and the minimum running speed among the first i
members who ran. Formally, if ai denotes the speed of the i-th member who participated in the race, then di=max(a1,a2,…,ai)−min(a1,a2,…,ai).

You want to minimize the sum of the discrepancies d1+d2+⋯+dn. To do this, you are allowed to change the order in
which the members run. What is the minimum possible sum that can be achieved?

Input
The first line contains a single integer n (1≤n≤2000)  — the number of members of the student council.

The second line contains n integers s1,s2,…,sn (1≤si≤109)  – the running speeds of the members.

Output
Print a single integer  — the minimum possible value of d1+d2+⋯+dn after choosing the order of the members.

Examples
inputCopy
3
3 1 2
outputCopy
3
inputCopy
1
5
outputCopy
0
inputCopy
6
1 6 3 3 6 3
outputCopy
11
inputCopy
6
104 943872923 6589 889921234 1000000000 69
outputCopy
2833800505
Note
In the first test case, we may choose to make the third member run first,
followed by the first member, and finally the second. Thus a1=2, a2=3, and a3=1. We have:

d1=max(2)−min(2)=2−2=0.
d2=max(2,3)−min(2,3)=3−2=1.
d3=max(2,3,1)−min(2,3,1)=3−1=2.
The resulting sum is d1+d2+d3=0+1+2=3. It can be shown that it is impossible to achieve a smaller value.

In the second test case, the only possible rearrangement gives d1=0, so the minimum possible result is 0.
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n;
vi arr;
int dp[2001][2001];
int solve(int i,int j){
	if(i > j){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int &ans = dp[i][j];
	return ans = (arr[j] - arr[i]) + min(solve(i+1,j),solve(i,j-1));
}
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	for(int &i:arr){
		cin >> i;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	sort(arr.begin(),arr.end());
	cout << solve(0,n-1) << '\n';
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
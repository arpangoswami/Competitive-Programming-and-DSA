/*
D. Armchairs
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
There are n armchairs, numbered from 1 to n from left to right.
Some armchairs are occupied by people (at most one person per armchair), others are not. The number of occupied armchairs is not greater than n2.

For some reason, you would like to tell people to move from their armchairs
 to some other ones. If the i-th armchair is occupied by someone and the j-th armchair is not, you can tell the person sitting in the i-th 
 armchair to move to the j-th armchair. The time it takes a person to move from the i-th armchair to the j-th one is |i−j| minutes. 
 You may perform this operation any number of times, but these operations must be done sequentially, 
 i. e. you cannot tell a person to move until the person you asked to move in the last operation has finished moving to their destination armchair.

You want to achieve the following situation: every seat that was initially
 occupied must be free. What is the minimum time you need to do it?

Input
The first line contains one integer n (2≤n≤5000) — the number of armchairs.

The second line contains n integers a1,a2,…,an (0≤ai≤1). ai=1 means that the 
i-th armchair is initially occupied, ai=0 means that it is initially free. The number of occupied armchairs is at most n2.

Output
Print one integer — the minimum number of minutes you have to spend to achieve the 
following situation: every seat that was initially occupied must be free.

Examples
inputCopy
7
1 0 0 1 0 0 1
outputCopy
3
inputCopy
6
1 1 1 0 0 0
outputCopy
9
inputCopy
5
0 0 0 0 0
outputCopy
0
Note
In the first test, you can perform the following sequence:

ask a person to move from armchair 1 to armchair 2, it takes 1 minute;
ask a person to move from armchair 7 to armchair 6, it takes 1 minute;
ask a person to move from armchair 4 to armchair 5, it takes 1 minute.
In the second test, you can perform the following sequence:

ask a person to move from armchair 1 to armchair 4, it takes 3 minutes;
ask a person to move from armchair 2 to armchair 6, it takes 4 minutes;
ask a person to move from armchair 4 to armchair 5, it takes 1 minute;
ask a person to move from armchair 3 to armchair 4, it takes 1 minute.
In the third test, no seat is occupied so your goal is achieved instantly.
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
vi arr;
vi ones;
int dp[5001][5001];
int n;
int solve(int idx,int oneIdx){
	if(oneIdx == ones.size()){
		return 0;
	}
	if(idx == n){
		return 1e9;
	}
	if(dp[idx][oneIdx] != -1){
		return dp[idx][oneIdx];
	}
	int &ans = dp[idx][oneIdx];
	if(arr[idx] == 1){
		return ans = solve(idx+1,oneIdx);
	}
	return ans = min(solve(idx+1,oneIdx),abs(ones[oneIdx] - idx) + solve(idx+1,oneIdx+1));
}
void solveQuestion(){
	cin >> n;
	ones.clear();
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i] == 1){
			ones.push_back(i);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	cout << solve(0,0) << '\n';
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
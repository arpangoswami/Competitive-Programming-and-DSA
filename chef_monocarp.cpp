/*
C. Chef Monocarp
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Chef Monocarp has just put n dishes into an oven. He knows that the i-th dish has its optimal cooking time equal to ti minutes.

At any positive integer minute T Monocarp can put no more than one dish out of the oven. If the i-th dish is put out at some minute T, then its unpleasant value is |T−ti| — the absolute difference between T and ti. Once the dish is out of the oven, it can't go back in.

Monocarp should put all the dishes out of the oven. What is the minimum total unpleasant value Monocarp can obtain?

Input
The first line contains a single integer q (1≤q≤200) — the number of testcases.

Then q testcases follow.

The first line of the testcase contains a single integer n (1≤n≤200) — the number of dishes in the oven.

The second line of the testcase contains n integers t1,t2,…,tn (1≤ti≤n) — the optimal cooking time for each dish.

The sum of n over all q testcases doesn't exceed 200.

Output
Print a single integer for each testcase — the minimum total unpleasant value Monocarp can obtain when he puts out all the dishes out of the oven. Remember that Monocarp can only put the dishes out at positive integer minutes and no more than one dish at any minute.

Example
inputCopy
6
6
4 2 4 4 5 2
7
7 7 7 7 7 7 7
1
1
5
5 1 2 4 3
4
1 4 4 4
21
21 8 1 4 1 5 21 1 8 21 11 21 11 3 12 8 19 15 9 11 13
outputCopy
4
12
0
0
2
21
Note
In the first example Monocarp can put out the dishes at minutes 3,1,5,4,6,2. That way the total unpleasant value will be |4−3|+|2−1|+|4−5|+|4−4|+|6−5|+|2−2|=4.

In the second example Monocarp can put out the dishes at minutes 4,5,6,7,8,9,10.

In the third example Monocarp can put out the dish at minute 1.

In the fourth example Monocarp can put out the dishes at minutes 5,1,2,4,3.

In the fifth example Monocarp can put out the dishes at minutes 1,3,4,5.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[401][201];
int solve(int time,int idx,vector<int> &arr){
	if(idx == (int)arr.size()){
		return 0;
	}
	if(time == 2*(int)arr.size()){
		return 1e9;
	}
	if(dp[time][idx]!=-1){
		return dp[time][idx];
	}
	return dp[time][idx] = min(abs(arr[idx] - time) + solve(time + 1,idx + 1,arr),solve(time + 1,idx,arr));
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	int ans = solve(1,0,arr);
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
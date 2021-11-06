/*
A. Office Keys
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n people and k keys on a straight line. Every person wants to get to the office which is located on the line as well.
 To do that, he needs to reach some point with a key, take the key and then go to the office.
  Once a key is taken by somebody, it couldn't be taken by anybody else.

You are to determine the minimum time needed for all n people to get to the office with keys.
 Assume that people move a unit distance per 1 second. If two people reach a key at the same time,
  only one of them can take the key. A person can pass through a point with a key without taking it.

Input
The first line contains three integers n, k and p (1 ≤ n ≤ 1 000, n ≤ k ≤ 2 000, 1 ≤ p ≤ 109) —
 the number of people, the number of keys and the office location.

The second line contains n distinct integers a1, a2, ..., an (1 ≤ ai ≤ 109) —
 positions in which people are located initially. The positions are given in arbitrary order.

The third line contains k distinct integers b1, b2, ..., bk (1 ≤ bj ≤ 109) —
 positions of the keys. The positions are given in arbitrary order.

Note that there can't be more than one person or more than one key in the same point. A person and a key can be located in the same point.

Output
Print the minimum time (in seconds) needed for all n to reach the office with keys.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,k,p;
int dp[1001][2001];
vi pos;
vi keys;
int solve(int i,int j){
	if(i < 0){
		return 0;
	}
	if(j < 0){
		return 1e12;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int timeIfPick = 1e12;
	if((keys[j] >= p && keys[j] <= pos[i]) || (keys[j] >= pos[i] && keys[j] <= p)){ // Office Key Person  & Person Key Office
		timeIfPick = abs(pos[i] - p);
	}
	else{
		timeIfPick = abs(pos[i] - keys[j]) + abs(keys[j] - p);
	}
	return dp[i][j] = min(solve(i,j-1),max(timeIfPick,solve(i-1,j-1)));
}
void solveQuestion(){
	cin >> n >> k >> p;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j] = -1;
		}
	}
	pos.resize(n);
	keys.resize(k);
	for(int &i:pos){
		cin >> i;
	}
	for(int &i:keys){
		cin >> i;
	}
	sort(pos.begin(),pos.end());
	sort(keys.begin(),keys.end());
	cout<<solve(n-1,k-1)<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
/*WACHOVIA - Wachovia Bank
#knapsack #dynamic-programming
Danilo Gheyi is a renowned bank robber. He is known worldwide for accomplishing the most profitable bank robbery, in Fortaleza, Ceará.
 Danilo and his friends dug a tunnel to get into the main chest. There were some bags, with different amounts of money or jewelry and weight.
  They had to leave about 50% of the total value, since the truck couldn't carry all the bags.

Danilo wasn't caught, and to show that he can do itall again, he is planning a robbery to one of the safer banks in USA -the Wachovia Bank.
He wants your help to maximize the amount stolen, avoiding a huge loss as it happened in Fortaleza.

Write a program that, given the maximum weight the truck is ableto carry and the information about each bag in the bank,
 determine the maximum value that Danilo can steal.

Input
The input consists of several instances. There is an integer N (1 ≤ N ≤ 200) in the first line; it stands for the number of instances.
 The first line of each instance contains two integers, K and M (8 ≤ K ≤ 1000 and 1 ≤ M ≤ 50) representing, respectively,
  the maximum weight the truck can handle and the amount of bags in the bank.
   The next M lines describe each bag with two integers A and B (8 ≤ A ≤ 200 and 1 ≤ B ≤ 25): the weight and the value of the bag, respectively.

Output
For each instance output a sentence “Hey stupid robber, you can get P.”, and P represents the maximum value Danilo can steal.

Example
Input:
3
34 5
178 12
30 1
13 7
34 8
87 6
900 1
900 25
100 10
27 16
131 9
132 17
6 5
6 23
56 21
100 25
1 25
25 25
100 2

Output:
Hey stupid robber, you can get 8.
Hey stupid robber, you can get 25.
Hey stupid robber, you can get 99.*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[51][1001];
int m,k;
vector<pii> arr;
int solve(int m,int k){
	if(m == 0 || k == 0){
		return 0;
	}
	if(dp[m][k] != -1){
		return dp[m][k];
	}
	if(arr[m-1].second <= k){
		return dp[m][k] = max(arr[m-1].first + solve(m-1,k - arr[m-1].second),solve(m-1,k));
	}
	return dp[m][k] = solve(m-1,k);
}
void solveQuestion(){
	cin >> k >> m;
	arr.resize(m);
	for(int i=0;i<m;i++){
		cin >> arr[i].second >> arr[i].first;
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=k;j++){
			dp[i][j] = -1;
		}
	}
	int ans = solve(m,k);
	cout<<"Hey stupid robber, you can get "<<dp[m][k]<<"."<<"\n";
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
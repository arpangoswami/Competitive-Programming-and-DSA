/*DCEPC501 - Save Thy Toys
#dynamic-programming
Leonard is very fond of buying rare and expensive science fiction toys. He keeps his collection in a sequential order of the date on which the toy was bought in a special closet so that his roomie Sheldon never gets hold of his toys. But because of his bad luck Leonard once loses a bet to Sheldon and Sheldon demands a share Leonard’s toys. Since Leonard doesn’t want to loose much money, he decides upon a strategy to reduce his loss to minimum.

Leonard, beginning from the first toy in his closet will pick some toys, say "x" toys in sequence. Sheldon will then pick the next "x" toys (Note that Sheldon picks equal no. of toys as picked by Leonard in his move unless the remaining toys are less than "x". In that case he picks all of the remaining). This will keep going on till no more toys are left in the closet for Leonard to pick. You are given the sequence of toys with their price. Help Leonard in maximizing the total price of all toys he picks.

Leonard in his each turn can either pick only 1 or 2 or 3 toys ("x" described above can take value either 1, 2 or 3).

Input
First line specifies T, the number of test cases.

Each test case contains N in the first line. Second line contains N integers as described above.

Output
Output 1 line for each test case giving the maximum possible value of the total sum of all toys Leonard picks.

Constraints
1<=T<=10

1<=N<=100000

1<=Price of toys<=1000000

Example
Input:
2
4
5 4 3 2
6
10 8 7 11 15 20

Output:
12
53


Explanation:

In 1st case, Leonard picks 3 toys in his first move with value 5,4,3 and Sheldon has no choice but to pick the last.
In 2nd case, Leonard picks 10, 8. Then Sheldon picks 7,11. And then Leonard picks the rest.*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n;
vector<int> arr;
int dp[100001];
int solve(int idx){
	if(idx >= n){
		return 0;
	}
	if(dp[idx]!=-1){
		return dp[idx];
	}
	if(idx == n-1 || idx == n-2 || idx == n-3){
		int s = 0;
		for(int i=idx;i<n;i++){
			s+= arr[i];
		}
		return s;
	}
	return dp[idx] = max({arr[idx] + solve(idx+2),arr[idx] + arr[idx+1] + solve(idx+4),arr[idx] + arr[idx+1] + arr[idx+2] + solve(idx+6)});
}
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	if(arr.size() <= 3){
		int sum = 0;
		for(int x:arr){
			sum += x;
		}
		cout<<sum<<"\n";
		return;
	}
	for(int i=0;i<=n;i++){
		dp[i] = -1;
	}
	cout<<solve(0)<<"\n";
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
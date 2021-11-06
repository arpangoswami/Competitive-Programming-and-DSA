/*
B. Checkout Assistant
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bob came to a cash & carry store, put n items into his trolley, and went to the checkout counter to pay. Each item is described by its price ci and time ti in seconds that a checkout assistant spends on this item. While the checkout assistant is occupied with some item, Bob can steal some other items from his trolley. To steal one item Bob needs exactly 1 second. What is the minimum amount of money that Bob will have to pay to the checkout assistant? Remember, please, that it is Bob, who determines the order of items for the checkout assistant.

Input
The first input line contains number n (1 ≤ n ≤ 2000). In each of the following n lines each item is described by a pair of numbers ti, ci (0 ≤ ti ≤ 2000, 1 ≤ ci ≤ 109). If ti is 0, Bob won't be able to steal anything, while the checkout assistant is occupied with item i.

Output
Output one number — answer to the problem: what is the minimum amount of money that Bob will have to pay.

Examples
inputCopy
4
2 10
0 20
1 5
1 3
outputCopy
8
inputCopy
3
0 1
0 10
0 100
outputCopy
111

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[4005][2005];
int solve(vector<pii> &items,const int &n,int idx,int time){
	if(idx == n){
		if(time >= n){
			return 0;
		}
		return 1e15;
	}
	if((time - n) >= (items.size() - idx)){
		return 0;
	}
	if(dp[time][idx]!=-1){
		return dp[time][idx];
	}
	return dp[time][idx] = min(solve(items,n,idx+1,time-1),items[idx].second + solve(items,n,idx+1,time + items[idx].first));
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> items(n);
	int maxTime = 0;
	for(int i=0;i<n;i++){
		cin >> items[i].first >> items[i].second;
		maxTime = max(maxTime,items[i].first);
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(items,n,0,n)<<"\n";
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
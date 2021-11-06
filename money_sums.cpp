/*https://cses.fi/problemset/task/1745/
You have n coins with certain values. Your task is to find all money sums you can create using these coins.

Input

The first input line has an integer n: the number of coins.

The next line has n integers x1,x2,…,xn: the values of the coins.

Output

First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.

Constraints
1≤n≤100
1≤xi≤1000
Example

Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> prefix(n);
	prefix[0] = arr[0];
	for(int i=1;i<n;i++){
		prefix[i] = arr[i] + prefix[i-1];
	}
	vector<bool> dp(prefix.back()+1);
	dp[0] = true;
	for(int i=0;i<n;i++){
		for(int j=prefix[i];j>=arr[i];j--){
			dp[j] = dp[j] | dp[j - arr[i]];
		}
	}
	vector<int> sol;
	for(int i=1;i<=prefix.back();i++){
		if(dp[i]){
			sol.push_back(i);
		}
	}
	cout<<sol.size()<<"\n";
	for(int x:sol){
		cout<<x<<" ";
	}
	return 0;
}
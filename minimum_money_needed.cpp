/*
Cody went to the market to buy some oranges for his N friends. There he finds orange wrapped in packets, with the price of i^th packet as val[i]. Now he wants to buy exactly W kg oranges, so he wants you to tell him what minimum price he should pay to buy exactly W kg oranges. Weight of i^th packet is i kg. If price of i^th packet is -1 then this packet is not available for sale. The market has infinite supply of orange packets.

Input Format
First line of input contains two space separated integers N and W, the number of friend he has and the amount of Oranges in kilograms which he should buy.

The second line contains W space separated integers in which the i^th^ integer specifies the price of a ‘i’kg apple packet. A value of -1 denotes that the corresponding packet is unavailable

Constraints
1 <= N,W,val[ ] <= 10^3

Output Format
Output a single integer denoting the minimum price Code should pay to get exactly W kg oranges. Else print -1 if it is not possible to fill the bag.

Sample Input
5 5
1 2 3 4 5
Sample Output
5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int dp[1005][1005];
int minVal(int n,int wt,vector<int> &arr){
	if(wt == 0){
		return 0;
	}
	if(n == 0){
		return 1e9;
	}
	if(dp[n][wt]!=-1){
		return dp[n][wt];
	}
	if(arr[n-1] == -1 || n>wt){
		return dp[n][wt] = minVal(n-1,wt,arr);
	}
	return dp[n][wt] = min(arr[n-1] + minVal(n,wt-n,arr),minVal(n-1,wt,arr));
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,w;
	cin>>n>>w;
	vector<int> arr(w);
	for(int i=0;i<w;i++){
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	n = arr.size();
	int val = minVal(n,w,arr);
	if(val >= 1e8){
		cout<<-1<<endl;
	}else{
		cout<<val<<endl;
	}
	return 0;
}
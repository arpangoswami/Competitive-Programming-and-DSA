/*EKO - Eko
#binary-search
Lumberjack Mirko needs to chop down M metres of wood.
 It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire.
  However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height
 and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact).
  Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres,
   and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively,
    while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary.
 That‟s why he wants to set his sawblade as high as possible.
  Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000)
 and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each
 tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

Output
The first and only line of output must contain the required height setting.

Example
Input:
4 7
20 15 10 17

Output:
15
Input:
5 20
4 42 40 26 46

Output:
36*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(int height,vector<int> &arr,int n,int req){
	int cnt = 0;
	for(int i=0;i<n;i++){
		cnt+=max(0LL,arr[i]-height);
	}
	return cnt >= req;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,req;
	cin >> n >> req;
	vector<int> arr(n);
	int maxm = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		maxm = max(maxm,arr[i]);
	}
	int low = 0,high = maxm,ans = low;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,arr,n,req)){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}
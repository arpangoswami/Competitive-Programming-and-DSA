/*Count Subarrays Problem Code: SUBINC Solved Submit

Read problems statements in Mandarin Chinese and Russian
Given an array A1, A2, ..., AN, count the number of subarrays of array A which are non-decreasing.
A subarray A[i, j], where 1 ≤ i ≤ j ≤ N is a sequence of integers Ai, Ai+1, ..., Aj.

A subarray A[i, j] is non-decreasing if Ai ≤ Ai+1 ≤ Ai+2 ≤ ... ≤ Aj. You have to count the total number of such subarrays.

Input
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the size of array.

The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output
For each test case, output in a single line the required answer.

Constraints
1 ≤ T ≤ 5
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109
Subtasks
Subtask 1 (20 points) : 1 ≤ N ≤ 100
Subtask 2 (30 points) : 1 ≤ N ≤ 1000
Subtask 3 (50 points) : Original constraints
Example
Input:
2
4
1 4 2 3
1
5

Output:
6
1
Explanation
Example case 1.
All valid subarrays are A[1, 1], A[1, 2], A[2, 2], A[3, 3], A[3, 4], A[4, 4].
Note that singleton subarrays are identically non-decreasing.

Example case 2.
Only single subarray A[1, 1] is non-decreasing.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
ll smallerThanLast(ll val,vector<ll> &arr,int idx,int n){
	int j=idx;
	ll last = val;
	while(j<n && arr[j]>=last){
		last = arr[j];
		j++;
	}
	return (j-idx);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<ll> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		vector<ll> length(n,-1);
		int i=0;
		while(i<n){
			ll len = smallerThanLast(arr[i],arr,i,n);
			length[i] = len;
			i+=len;
		}
		ll ans = 0;
		for(int i=0;i<n;i++){
			if(length[i]!=-1){
				ll l = length[i];
				ans+=(l*(l+1))/2;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
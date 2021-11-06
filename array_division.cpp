/*
Array Division
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You are given an array containing n positive integers.

Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

Input

The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.

The next line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print one integer: the maximum sum in a subarray in the optimal division.

Constraints
1≤n≤2⋅105
1≤k≤n
1≤xi≤109
Example

Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8. The largest sum is the last sum 8.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(int mid,vector<int> &arr,int n,int k){
	int i = 0;
	int cnt = 1;
	int fill = 0;
	while(i < n){
		if(arr[i] + fill > mid){
			fill = 0;
			cnt++;
		}else{
			fill += arr[i];
			i++;
		}
	}
	return cnt <= k;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	int maxm = 1,s = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		s+=arr[i];
		maxm = max(maxm,arr[i]);
	}
	int low = maxm,high = s,ans = s;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,arr,n,k)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
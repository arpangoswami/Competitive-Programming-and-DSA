/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}.
 There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board. Return the ans % 10000003

Input Format
First line contains three space seperated integers N,K and T ,where
N = Size of array,
K = No of painters available ,
T = Time taken to print each board by one painter
Next line contains N space seperated positive integers denoting size of N boards.

Constraints
1<=N<=100000
1<=K<=100000
1<=T<=1000000
1<=Li<=100000

Output Format
Return minimum time required to paint all boards % 10000003.

Sample Input
2 2 5
1 10
Sample Output
50
Explanation
The first painter can paint the first board in 5 units of time and the second painter will
 take 50 units of time to paint the second board. Since both can paint simultaneously , the total time required to paint both the boards is 50.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
bool check(int *arr,int mid,int n,int k,int t){
	int cnt = 1;
	int curr = 0;
	for(int i=0;i<n;i++){
		curr+=(arr[i]*t);
		if(curr > mid){
			curr = arr[i]*t;
			cnt++;
		}
	}
	return cnt <= k;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k,t;
	cin >> n >> k >> t;
	int *arr = new int [n];
	int s = 0;
	int maxm = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		s+=(arr[i]*t);
		maxm = max(arr[i],maxm);
	}
	int low = maxm*t,high = s,ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(arr,mid,n,k,t)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout << ans%10000003 << "\n";
	delete []arr;
	return 0;
}
/*
https://discuss.codechef.com/t/remove-subarray-sum-to-make-it-divisible-by-k/67441
Given N numbers in an array and a number K,
find the length of the shortest subarray to be removed such that the rest of the numbers when added up are divisible by K.
Note:- It is allowed to remove an empty subarray(length 0) and the whole array (length N)
Constraints:-
1<=N<=1e5
1<=A[i]<=1e9
1<=K<=1e9

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char *argv[]){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	unordered_map<int,int> mp;
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		arr[i]%=k;
		sum += arr[i];
		sum %= k;
	}
	if(sum == 0){
		cout<<0<<"\n";
		return 0;
	}
	int ans = n;
	int rem = sum;
	sum = 0;
	mp[0] = -1;
	for(int i=0;i<n;i++){
		sum += arr[i];
		sum %= k;
		int req = (sum - rem);
		req = (req + k)%k;
		if(mp.count(req)){
			ans = min(ans,i-mp[req]);
		}
		mp[sum] = i;
	}
	cout<<ans<<"\n";
	return 0;
}
/*Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format
First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1
Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n,k;
		cin >> n >> k;
		vector<int> arr(n);
		unordered_map<int,int> mp; 
		for(int i=0;i<n;i++){
			cin >> arr[i];
			mp[arr[i]] = i;
		} 
		if(k >= n){
			sort(arr.begin(),arr.end(),greater<int>());
			for(int x:arr){
				cout << x << " ";
			}
		}else{
			for(int i=n;i>=1 && k>0;i--){
				int ideal = n - i;
				if(ideal == mp[i]){
					continue;
				}else{
					int idx = mp[i];
					int val = arr[ideal];
					swap(arr[ideal],arr[mp[i]]);
					mp[val] = idx;
					mp[i] = ideal;
					k--;
				}
			}
			for(int x:arr){
				cout << x << " ";
			}
		}
	}
	return 0;
}
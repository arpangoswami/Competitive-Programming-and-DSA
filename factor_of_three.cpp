/*
Factor of 3
Problem Description
Given an array arr, of size N, find whether it is possible to rearrange the elements of array such that sum of no two adjacent elements is divisible by 3.

Constraints
1 <= T <= 10

2 <= N <= 10^5

1 <= arr[i] <= 10^5

Input
First line contains integer T denoting the number of testcases.

Each test cases consists of 2 lines as follows-

First line contains integer N denoting the size of the array.

Second line contains N space separated integers.

Output
For each test case print either "Yes" or "No" (without quotes) on new line.

Time Limit
1

Examples
Example 1

Input

1

4

1 2 3 3

Output

Yes

Explanation

Some of the rearrangements can be {2,1,3,3}, {3,3,1,2}, {2,3,3,1}, {1,3,3,2},...

We can see that there exist at least 1 combination {3,2,3,1} where sum of 2 adjacent number is not divisible by 3. Other combinations can be {1,3,2,3}, {2,3,1,3}.

Hence the output is Yes.

Example 2

Input

1

4

3 6 1 9

Output

No

Explanation

All possible combination of {3,6,1,9} are

{1,3,6,9}, {1,3,9,6}, {1,6,9,3}, {1,6,3,9}, {1,9,3,6}, {1,9,6,3},

{6,1,3,9}, {6,1, 9,3}, {6,3,1,9}, {6,3,9,1}, {6,9,1,3}, {6,9,3,1},

{3,1,6,9}, {3,1,9,6}, {3,9,1,6}, {3,9,6,1}, {3,6,1,9}, {3,6,9,1},

{9,1,3,6}, {9,1,6,3}, {9,3,1,6}, {9,3,6,1}, {9,6,1,3}, {9,6,3,1}.

Since none of these combinations satisfy the condition, the output is No.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<int> arr(n);
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			if(arr[i]%3 == 0){
				cnt3++;
			}else if(arr[i]%3 == 1){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		if(n%2 == 0){
			if(cnt1 + cnt2 == cnt3){
				cout<<"Yes"<<"\n";
			}else{
				cout<<"No"<<"\n";
			}
		}else{
			if(abs((cnt1+cnt2) - cnt3) == 1){
				cout<<"Yes"<<"\n";
			}else{
				cout<<"No"<<"\n";
			}
		}
	}
	return 0;
}
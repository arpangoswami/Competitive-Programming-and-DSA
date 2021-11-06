/*
Chef and Laddus For Children Problem Code: CHELADDUSolvedSubmit

 
Chef has N laddus, i-th of which has a size si. There are no two laddues with equal size, i.e. all the laddus have different sizes.

There are K children that came to meet Chef today. Chef wants to give a single laddu to each of these K children. Also, he wants to minimize the difference in the sizes which the children get, i.e. he wants to minimize the maximum difference in the sizes of the laddus distributed. This is because children feel jealous of each other if the other one has a bigger laddu that him/her.

In other words, find a subset of size K which minimizes the value of max_element of the subset - min_element of the subset, and output this minimum difference.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space separated integers N, K.

The second line of each test case contains N space separated denoting the array s

Output
For each test case, output a single integer corresponding to the minimum difference in the sizes of the laddus distributed to the children.

Constraints
1 ≤ T ≤ 10
1 ≤ K ≤ N ≤ 105
1 ≤ si ≤ 109
Scoring infomation
8% score for N ≤ 10
12% score for N ≤ 100
20% score for N ≤ 1000
60% score for original constraints
Example
Input
3
4 1
3 4 2 5
5 2
1 5 3 7 9
6 3
1 12 7 9 5 17

Output
0
2
4
Explanation
Example 1. There is only one child, so Chef can give him any laddu. The difference between maximum and minimum size of the laddu will be zero.

Example 2. There are two children now. Chef can give one child a laddu of size 5 and other of 7. The difference between the maximum and minimum size of the laddu will is 2. It's impossible for Chef to get lower difference between the sizes of laddus.

Example 3. There are three children now. Chef can give one child a laddu of size 5 and other of 7, and the remaining one as 9. The difference between the maximum and minimum size of the laddu will is 4. This is the minimum possible difference between the sizes of laddu that Chef can get.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int ans = arr[k-1] - arr[0];
	for(int i=1;i<n;i++){
		if((i + k - 1) == n){
			break;
		}
		ans = min(ans,arr[i+k-1] - arr[i]);
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
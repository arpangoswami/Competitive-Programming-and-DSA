/*
Problem
A combination lock has W wheels, each of which has the integer values 1 through N on it, in ascending order.

At any moment, each wheel shows a specific value on it. Xi is the initial value shown on the i-th wheel.

You can use a single move to change a wheel from showing the value X to showing either X+1 or X-1, wrapping around between 1 and N. For example, if a wheel currently shows the value 1, in one move you can change its value to 2 or N.

Given all wheels' initial values, what is the minimum number of moves to get all wheels to show the same value?

Input
The first line of the input gives the number of test cases, T. T test cases follow.

The first line of each test case contains the two integers W and N.

The second line contains W integers. The i-th integer is Xi.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of moves to get all wheels to show the same value.

Limits
Time limit: 40 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Xi ≤ N.
Test Set 1
1 ≤ W ≤ 1000.
2 ≤ N ≤ 1000.
Test Set 2
1 ≤ W ≤ 1000.
2 ≤ N ≤ 109.
Test Set 3
1 ≤ W ≤ 105.
2 ≤ N ≤ 109.
Sample

Input
 	
Output
 
2
3 5
2 3 4
4 10
2 9 3 8



  
Case #1: 2
Case #2: 8
  
In Sample Case #1, the best solution is to get all wheels to show value 3, which would take a total of 2 moves: the first wheel would move once (from value 2 to value 3), the second wheel would not move (it already shows value 3), and the third wheel would move once (from value 4 to value 3).

For reference, it would take 5 moves to get all wheels to show value 1, 3 moves to get all wheels to show value 2, 3 moves to get all wheels to show value 4, and 5 moves to get all wheels to show value 5.

In Sample Case #2, the best solutions are to get all wheels to show either value 1, 2, 9 or 10, which would take a total of 8 moves.

1
4 10
2 9 3 8
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
vector<int> prefix;
inline int getSum(int i,int j){
	if(i > j){
		return 0;
	}
	else if(i == 0){
		return prefix[j];
	}
	return prefix[j] - prefix[i-1];
}
int leftInflexion(vector<int> &arr,int low,int high,int target,int N){
	if(low > high){
		return -1;
	}
	int ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		int normal = (target - arr[mid]);
		int wrapAround = (arr[mid] + N - target);
		if(normal <= wrapAround){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return ans;
}
int rightInflexion(vector<int> &arr,int low,int high,int target,int N){
	if(low > high){
		return -1;
	}
	int ans = low;
	while(low <= high){
		int mid = (low + high)/2;
		int normal = (arr[mid] - target);
		int wrapAround = (target + N - arr[mid]);
		if(normal <= wrapAround){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}
inline int leftPart(int leftPoint,int idx,int N,vector<int> &arr){
	if(leftPoint == -1){
		return 0;
	}
	int normal = (idx - leftPoint + 1) * arr[idx] - getSum(leftPoint,idx);
	if(leftPoint == 0){
		return normal;
	}
	int wrapAround = getSum(0,leftPoint - 1) - leftPoint*(arr[idx] - N);
	return (normal + wrapAround);
}
inline int rightPart(int rightPoint,int idx,int N,vector<int> &arr){
	if(rightPoint == -1){
		return 0;
	}
	int n = arr.size();
	int normal = getSum(idx,rightPoint) - (rightPoint - idx + 1) * arr[idx];
	if(rightPoint == (int)arr.size() - 1){
		return normal;
	}
	int wrapAround = (n - 1 - rightPoint) * (arr[idx] + N) - getSum(rightPoint+1,n-1);
	return normal + wrapAround;
}
void solveQ(){
	int n,space;
	cin >> n >> space;
	prefix.resize(n);
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	prefix[0] = arr[0];
	for(int i=1;i<n;i++){
		prefix[i] = prefix[i-1] + arr[i];
	}
	int ans = 1e17;
	for(int i=0;i<n;i++){
		int leftPoint = leftInflexion(arr,0,i,arr[i],space);
		int rightPoint = rightInflexion(arr,i,n-1,arr[i],space);
		int l = leftPart(leftPoint,i,space,arr);
		int r = rightPart(rightPoint,i,space,arr);
		ans = min(ans,l+r);
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}
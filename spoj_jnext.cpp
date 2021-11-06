/*
JNEXT - Just Next !!!
#ad-hoc-1
DevG likes too much fun to do with numbers. Once his friend Arya came and gave him a challenge, he gave DevG an array of digits which is forming a number currently (will be called as given number). DevG was challanged to find the just next greater number which can be formed using digits of given number. Now DevG needs your help to find that just next greater number and win the challenge.

Input
The first line have t number of test cases (1 <= t <= 100). In next 2*t lines for each test case first there is number n (1 <= n <= 1000000) which denotes the number of digits in given number and next line contains n digits of given number separated by space.

Output
Print the just next greater number if possible else print -1 in one line for each test case.

Note : There will be no test case which contains zero in starting digits of any given number.

Example
Input:
2
5
1 5 4 8 3
10
1 4 7 4 5 8 4 1 2 6

Output:
15834
1474584162
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int swapIndex1 = -1;
	for(int i=n-1;i>0;i--){
		if(arr[i] > arr[i-1]){
			swapIndex1 = i-1;
			break;
		}
	}
	
	if(swapIndex1 == -1){
		cout<<-1<<"\n";
		return;
	}
	int swapIndex2 = -1;
	for(int i=n-1;i>swapIndex1;i--){
		if(arr[i] > arr[swapIndex1]){
			swapIndex2 = i;
			break;
		}
	}
	swap(arr[swapIndex1],arr[swapIndex2]);
	reverse(arr.begin() + swapIndex1 + 1,arr.end());
	for(int x:arr){
		cout<<x;
	}
	cout<<"\n";
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
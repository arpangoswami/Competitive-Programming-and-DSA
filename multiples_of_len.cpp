/*
A. Multiples of Length
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of n integers.

You want to make all elements of a equal to zero by doing the following operation exactly three times:

Select a segment, for each number in this segment we can add a multiple of len to it, where len is the length of this segment (added integers can be different).
It can be proven that it is always possible to make all elements of a equal to zero.

Input
The first line contains one integer n (1≤n≤100000): the number of elements of the array.

The second line contains n elements of an array a separated by spaces: a1,a2,…,an (−109≤ai≤109).

Output
The output should contain six lines representing three operations.

For each operation, print two lines:

The first line contains two integers l, r (1≤l≤r≤n): the bounds of the selected segment.
The second line contains r−l+1 integers bl,bl+1,…,br (−1018≤bi≤1018): the numbers to add to al,al+1,…,ar, respectively; bi should be divisible by r−l+1.
Example
inputCopy
4
1 3 2 4
outputCopy
1 1 
-1
3 4
4 2
2 4
-3 -6 -6
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
	if(n == 1){
		cout<<1<<" "<<1<<"\n";
		cout<<0<<"\n";
		cout<<1<<" "<<1<<"\n";
		cout<<0<<"\n";
		cout<<1<<" "<<1<<"\n";
		cout<<-arr[0]<<"\n";
	}else{
		cout<<1<<" "<<1<<"\n";
		cout<<-arr[0]<<"\n";
		cout<<1<<" "<<n<<"\n";
		cout<<0<<" ";
		for(int i=1;i<n;i++){
			cout<<-n * arr[i]<<" ";
		}
		cout<<"\n";
		cout<<2<<" "<<n<<"\n";
		for(int i=1;i<n;i++){
			cout<<(n-1) * arr[i]<<" ";
		}
		cout<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
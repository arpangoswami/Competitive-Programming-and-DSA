/*
Ferris Wheel
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input

The first input line contains two integers n and x: the number of children and the maximum allowed weight.

The next line contains n integers p1,p2,…,pn: the weight of each child.

Output

Print one integer: the minimum number of gondolas.

Constraints
1≤n≤2⋅105
1≤x≤109
1≤pi≤x
Example

Input:
4 10
7 2 3 9

Output:
3
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,wt;
	cin >> n >> wt;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int i=0,j=n-1;
	int cnt = 0;
	while(i<=j){
		if(arr[i] + arr[j] > wt){
			cnt++;
			j--;
		}else{
			i++;
			j--;
			cnt++;
		}
	}
	if(i == j){
		cnt++;
	}
	cout<<cnt<<"\n";
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
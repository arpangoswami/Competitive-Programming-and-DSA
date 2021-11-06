/*
C. Pekora and Trampoline
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a trampoline park with n trampolines in a line. The i-th of which has strength Si.

Pekora can jump on trampolines in multiple passes. She starts the pass by jumping on any trampoline of her choice.

If at the moment Pekora jumps on trampoline i, the trampoline will launch her to position i+Si, 
and Si will become equal to max(Si−1,1). In other words, Si will decrease by 1, except of the case Si=1, when Si will remain equal to 1.

If there is no trampoline in position i+Si, then this pass is over. Otherwise, Pekora will continue 
the pass by jumping from the trampoline at position i+Si by the same rule as above.

Pekora can't stop jumping during the pass until she lands at the position larger than n (in which there is no trampoline). Poor Pekora!

Pekora is a naughty rabbit and wants to ruin the trampoline park by reducing all Si to 1. 
What is the minimum number of passes she needs to reduce all Si to 1?

Input
The first line contains a single integer t (1≤t≤500) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤5000) — the number of trampolines.

The second line of each test case contains n integers S1,S2,…,Sn (1≤Si≤109), where Si is the strength of the i-th trampoline.

It's guaranteed that the sum of n over all test cases doesn't exceed 5000.

Output
For each test case, output a single integer — the minimum number of passes Pekora needs to do to reduce all Si to 1.

Example
inputCopy
3
7
1 4 2 2 2 2 2
2
2 3
5
1 1 1 1 1
outputCopy
4
3
0
Note
For the first test case, here is an optimal series of passes Pekora can take. 
(The bolded numbers are the positions that Pekora jumps into during these passes.)

[1,4,2,2,2,2,2]
[1,4,1,2,1,2,1]
[1,3,1,2,1,1,1]
[1,2,1,2,1,1,1]
For the second test case, the optimal series of passes is show below.

[2,3]
[1,3]
[1,2]
For the third test case, all Si are already equal to 1.


*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n),arr1;
	for(int &i:arr){
		cin >> i;
	}
	vi pref(n);
	int ans = 0;
	for(int i=0;i<n;i++){
		int val = pref[i];
		if(val < (arr[i] - 1)){
			ans += (arr[i] - 1 - val);
			val += (arr[i] - 1 - val);
		}
		if(i < (n-1)){
			pref[i+1] += (val - (arr[i]-1)); //if previous step happened zero pekoras are added (since we had to add steps here to make it 1),
			//otherwise extra pekoras are added here i.e pekora had stepped on trampoline i more times than necessary and this trampoline was already at strength 1, 
			//now extra times she stepped here were also transferred to the very next trampoline.
		}
		// val denotes the minimum times pekora has stepped on this trampoline. Before this iteration pref[i] stored the number of times pekora stepped here
		// due to result of previous pass
		for(int j=i+2;j<=min(n-1,i+arr[i]);j++){
			pref[j]++;
		}
	}
	cout<<ans<<'\n';
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
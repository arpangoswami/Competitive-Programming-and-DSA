/*
Tasks and Deadlines
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d−f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)

What is your maximum reward if you act optimally?

Input

The first input line has an integer n: the number of tasks.

After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.

Output

Print one integer: the maximum reward.

Constraints
1≤n≤2⋅105
1≤a,d≤106
Example

Input:
3
6 10
8 15
5 12

Output:
2
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(),arr.end());
	int time = 0,pf = 0;
	for(int i=0;i<n;i++){
		int fin = time + arr[i].first;
		pf += (arr[i].second - fin);
		time = fin;
	}
	cout<<pf<<"\n";
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
/*
Restaurant Customers
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers?

Input

The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output

Print one integer: the maximum number of customers.

Constraints
1≤n≤2⋅105
1≤a<b≤109
Example

Input:
3
5 8
2 4
3 9

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
	vector<int> arrive(n);
	vector<int> depart(n);
	for(int i=0;i<n;i++){
		cin >> arrive[i] >> depart[i];
	}
	int curr = 0,maxm = 0;
	sort(arrive.begin(),arrive.end());
	sort(depart.begin(),depart.end());
	int i=0,j=0;
	while(i<n && j<n){
		if(depart[i] >= arrive[j]){
			curr++;
			j++;
		}else{
			curr--;
			i++;
		}
		maxm = max(maxm,curr);
	}
	cout<<maxm<<"\n";
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
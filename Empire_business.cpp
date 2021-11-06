/*
Empire Business Problem Code: SOLDVAL
Add problem to Todo list
Submit (Practice)

 
“Jesse, you asked me if I was in the meth business, or the money business… Neither. I’m in the empire business.”

Walter’s sold his stack in Gray Matter Technologies, a company which he deserved half a credit, for peanuts. Now this company is worth a billion dollar company. Walter wants to get it's shares to have his Empire Business back and he founds an opportunity.

There are N persons having shares A1,A2,A3,…AN in this company. Walter can buy these shares with their minimum Sold Values.

Sold Values of a person's share i (1≤i≤N) with another person's share j (1≤j≤N) is equal to Aj+|i−j|. So, a person's share can have N possible sold values and Walter has to find minimum sold value among them for each person.

Since Walter has to run his meth business also he asks you to find minimum sold value for each person.

Input:
First line will contain T, number of test cases. Then the testcases follow.
The First line of each test case contains a integer N.
The Second line of each test case contains N space integers namely A1,A2,…AN.
Output:
For each test case, output in single line N space integers denoting minimum sold value for each person.

Constraints
1≤T≤105
1≤N≤2∗106
1≤Ai≤109
Sum of N over all test cases will not exceed 2∗106.

Sample Input:
2
5
6 5 5 5 2
5
1 2 3 4 5
Sample Output:
6 5 4 3 2
1 2 3 4 5
Explanation
For first case:

Sold value for index 1: 6,6,7,8,6
Sold value for index 2: 7,5,6,7,5
Sold value for index 3: 8,6,5,6,4
Sold value for index 4: 9,7,6,5,3
Sold value for index 5: 10,8,7,6,2
Minimum sold value for each index will be 6,5,4,3,2.
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
	vector<int> sol(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sol[i] = arr[i];
	}
	int best = sol[0] + 1;
	for(int i=1;i<n;i++){
		if(arr[i] < best){
			best = arr[i];
		}
		sol[i] = best;
		best++;
	}
	best = arr[n-1] + 1;
	for(int i=n-2;i>=0;i--){
		if(arr[i] < best){
			best = arr[i];
		}
		sol[i] = min(sol[i],best);
		best++;
	}
	for(int x:sol){
		cout<<x<<" ";
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
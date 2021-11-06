/*
Roads in Chefland Problem Code: CROADS
Add problem to Todo list
Submit

 
Read problems statements in Hindi, Mandarin Chinese, Russian, Vietnamese, and Bengali as well.
In Chefland, there are N cities (numbered 1 through N). Initially, there are no roads between them. The Mayor of Chefland has ordered engineers to build roads across Chefland in such a way that each city is reachable from all other cities.

For each pair of distinct cities i and j, the cost of building a road between these cities is equal to (i∧j), where ∧ denotes the bitwise AND operation. However, leaders of the cities have a weird condition ― they only allow roads with positive costs to be built from their cities.

Help the Mayor find the minimum cost of building roads in the required way or determine that it is impossible.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print a single line containing one integer ― the minimum cost of building the roads or −1 if it is impossible.

Constraints
1≤T≤2⋅105
2≤N≤109
Example Input
2
3
5
Example Output
3
8
Explanation
Example case 1: We can connect city 1 with city 3 by a road with cost 1 and city 3 with city 2 by a road with cost 2.

https://www.codechef.com/problems/CROADS
*/

//Key Idea:- For connecting a number the cost involved is the number to be connected's least significant bit.
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	for(int i=1;i<=30;i++){
		if(n == (1LL << i)){
			cout << -1 << '\n';
			return;
		}
	}
	int ans = 0;
	for(int i=0;i<=30;i++){
		int firstTerm = (1LL << i);
		if(firstTerm > n){
			break;
		}
		int diff = (1LL << (i+1));
		int terms = (n-firstTerm)/diff + 1;
		ans += (firstTerm * (terms - 1));
		if(i > 0){
			ans += firstTerm;
		}
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
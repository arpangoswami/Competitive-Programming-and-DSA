/*
E. Two Round Dances
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

One day, n people (n is an even number) met on a plaza and made two round dances, each round dance consists of exactly n2 people. Your task is to find the number of ways n people can make two round dances if each round dance consists of exactly n2 people. Each person should belong to exactly one of these two round dances.
Round dance is a dance circle consisting of 1 or more people. Two round dances are indistinguishable (equal) if one can be transformed to another by choosing the first participant and the order of rotation (clockwise or counterclockwise). For example, round dances [1,3,4,2], [4,2,1,3] and [1,2,41,3,4] are indistinguishable.
For example, if n=2 then the number of ways is 1-: one round dance consists of the first person and the second one of the second person.
For example, if n=4 then the number of ways is 3. Possible options:
one round dance — [1,2], another — [3,4];
one round dance — [2,4], another — [3,1];
one round dance — [4,1], another — [3,2].

Your task is to find the number of ways n people can make two round dances if each round dance consists of exactly n2 people.

Input
The input contains one integer n (2≤n≤20), n is an even number.

Output
Print one integer — the number of ways to make two round dances. It is guaranteed that the answer fits in the 64--bit integer data type.

Examples
Input
2

Output
1

Input
4

Output
3

Input
8

Output
1260

Input
20

Output
12164510040883200
*/
#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int fact(int n){
	if(n == 0){
		return 1;
	}
	return n * fact(n-1);
}
void solveQuestion(){
	int n;
	cin >> n;
	int half = n/2;
	int ans = fact(n)/(2*fact(half) * fact(half));
	ans *= (fact(half-1) * fact(half-1));
	cout<<ans<<"\n";
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
/*
Boolean Parenthesization Submissions: 11714   Accuracy: 36.9%   Difficulty: Hard   Marks: 8
Associated Course(s):   Geeks Classes   Geeks Classes- Algorithms
          
Problems
Given a boolean expression with following symbols.

Symbols
    'T' ---> true
    'F' ---> false

And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

For Example:
The expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).

Return No_of_ways Mod 1003.

Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is length of string N.  1<=N<=100
Second line is string S (boolean expression).
Output:
No of ways Mod 1003.
 

Example:
Input:
2
7
T|T&F^T
5
T^F|F

Output:
4
2

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int mod = 1003;
int dp[502][502][2];
int solve(string &s,int i,int j,bool isTrue){
	if(i == j){
		if(isTrue){
			if(s[i] == 'T'){
				return 1;
			}
			return 0;
		}else{
			if(s[i] == 'F'){
				return 1;
			}
			return 0;
		}
	}
	if(dp[i][j][isTrue]!=-1){
		return dp[i][j][isTrue];
	}
	int ans = 0;
	for(int k=i+1;k<j;k+=2){
		int leftTrue = solve(s,i,k-1,1);
		int leftFalse = solve(s,i,k-1,0);
		int rightTrue = solve(s,k+1,j,1);
		int rightFalse = solve(s,k+1,j,0);
		if(s[k] == '^'){
			if(isTrue){
				ans += (leftTrue * rightFalse) + (leftFalse * rightTrue);
			}else{
				ans += (leftTrue * rightTrue) + (leftFalse * rightFalse);
			}
		}else if(s[k] == '|'){
			if(isTrue){
				ans += (leftFalse * rightTrue) + (leftTrue * rightTrue) + (leftTrue * rightFalse); 
			}else{
				ans += (leftFalse * rightFalse);
			}
		}else if(s[k] == '&'){
			if(isTrue){
				ans += (leftTrue * rightTrue);
			}else{
				ans += (leftFalse * rightFalse) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
			}	
		}
		ans %= mod;
	}
	return dp[i][j][isTrue] = ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	memset(dp,-1,sizeof(dp));
	cout<<solve(s,0,n-1,1)<<"\n";
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
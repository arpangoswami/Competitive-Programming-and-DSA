/*MBLAST - BLAST
#dynamic-programming
Đọc đề đẹp hơn ở:
https://codeforces.com/group/FLVn1Sc504/contest/274710/problem/N
https://codeforces.com/group/FLVn1Sc504/contest/274505/problem/K
English	Vietnamese
There are given two strings, A and B. An expansion of some string X is a string created by adding or inserting any number (zero, one or more) of blanks anywhere in the string, or in the begining or the end of the string. Eg., if the string X is ‘abcbcd’, then the strings 'abcb-cd', '-a-bcbcd-' and 'abcb-cd-' are expansions of the string X (blanks are denoted by the character ‘-‘).

If A1 is an expansion of the string A, and B1 is and expansion of the string B, and if A1 and B1 are of the same length, then we define the distance of the strings A1 and B1 as the sum of the distances of the characters on the same positions in these strings. We define the distance of two characters as the absolute difference of their ASCII codes, except the distance of the blank and another character, which is given (and equal for all characters).

You are to write a program which finds the expansions A1 and B1 of strings A and B, that have the smallest difference.

Input
The first line of the input file consists of the string A, and the second line of string B. They are consisted only of lower case characters of the english alphabet (a-z), and the number of characters in any of the strings is less than or equal to 2000.

The third line consists of an integer K, 1 ≤ K ≤ 100, the distance of the blank and the other characters.

Output
The first only line of the input file should consist of the smallest distance as defined in the text of the task.

Sample
Input:
cmc
snmn
2

output:
10
Input:
koiv
ua
1

output:
5
input: 
mj
jao
4

output:
12
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int spaceInsertion(string &a,string &b,int m,int n,int cost,vector<vector<int>> &dp){
	if(m<0 || n<0){
		return INT_MAX;
	}
	if(m == 0 || n == 0){
		int g = (m > n) ? m : n;
		return cost * g;
	}
	if(dp[m][n]!=-1){
		return dp[m][n];
	}
	return dp[m][n] = min({abs(a[m-1] - b[n-1]) + spaceInsertion(a,b,m-1,n-1,cost,dp) , cost + spaceInsertion(a,b,m,n-1,cost,dp), cost + spaceInsertion(a,b,m-1,n,cost,dp)});
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b;
	cin>>a>>b;
	int m = a.size(),n = b.size();
	int cost;
	cin>>cost;
	vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
	cout<<spaceInsertion(a,b,m,n,cost,dp)<<endl;
	return 0;
}
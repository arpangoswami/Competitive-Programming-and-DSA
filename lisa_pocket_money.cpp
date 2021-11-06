/*
LISA - Pocket Money
no tags 
Young people spend a lot of money on things like sweets, music CDs, mobile phones and so on. But most young girls/boys have one problem: Their pocket money is not enough for all these jolly things. Little Lisa Listig is one of these poor girls with a small pocket money budget. Last month her pocket money lasted only one week. So she decided to enter into negotiations with her father. Her father Tomm - a mathematician - had an incredibly ingenious idea: He wrote down some fancy digits with operators (+,*) in between them on a sheet of paper and allowed Lisa to insert brackets. Then he declared that the result of that arithmetic expression is Lisa's new pocket money. Now it's Lisa's task to maximize her pocket money. As her father was surprised what a huge sum of money Lisa got for her result, he decided to minimize the result of the expression for his son Manfred. Now it's your task to calculate the results obtained by Lisa and her father.

Input
The first line of input contains the number of testcases k ( k< 5000 ). Each of the following k lines consists of an arithemtic expression. This expression consists of numbers (0-9) seperated by one of the two operators '*' and '+'. There are no spaces between the characters. Each line contains less than 100 characters.

Output
For each expression output the result obtained by Lisa and the result obtained by her father separated by one space. The results of the calculations are smaller than 264.

Example
Input:
1
1+2*3+4*5

Output:
105 27
Two possible expressions for the first testcase:

105 = (1+2)*(3+4)*5
27  = 1+2*3+4*5
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[101][101];
int solveMin(string &s,int i,int j){
	if(i == j){
		return s[i] - '0';
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int ans = LONG_MAX;
	for(int k=i;k<=(j-2);k+=2){
		int leftAns = solveMin(s,i,k);
		int rightAns = solveMin(s,k+2,j);
		char oper = s[k+1];
		if(oper == '+'){
			ans = min(ans,leftAns + rightAns);
		}else{
			ans = min(ans,leftAns * rightAns);
		}
	}
	return dp[i][j] = ans;
}
int solveMax(string &s,int i,int j){
	if(i == j){
		return s[i] - '0';
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int ans = 0;
	for(int k=i;k<=(j-2);k+=2){
		int leftAns = solveMax(s,i,k);
		int rightAns = solveMax(s,k+2,j);
		char oper = s[k+1];
		if(oper == '+'){
			ans = max(ans,leftAns + rightAns);
		}else{
			ans = max(ans,leftAns * rightAns);
		}
	}
	return dp[i][j] = ans;
}
void solveQuestion(){
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	cout<<solveMax(s,0,n-1)<<" ";
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	cout<<solveMin(s,0,n-1)<<"\n";
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
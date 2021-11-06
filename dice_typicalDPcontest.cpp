/*
D - Dice 
Run time limit: 2 sec / Memory limit: 256 MB

Problem Statement
When you roll the dice N times, look for the probability that the product will be multiples of D. 

Input Format
The input is given by the standard input in the following format.
N
 
D

Output Format
Output the answer to one line. When the absolute error is as follows, it is judged to be justifiable. 
10 ^ (-6)
Sample Input 1
2 6
Sample Output 1
0.416666667
There are 36 combinations of two rolls of the dice, of which 15 have a product multiple of 6, so the probability of asking is 15/36.
Sample Input 2
3 2
Sample Output 2
0.875000000
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
int sz = 2e5+5;
int power2,power3,power5,n;
double dp[101][62][62][62];
double solve(int i,int p2,int p3,int p5){
	if(p2 == 0 && p3 == 0 && p5 == 0){
		return 1.00;
	}
	if(i == 0){
		return 0.00;
	}
	if(dp[i][p2][p3][p5] > -0.9){
		return dp[i][p2][p3][p5];
	}
	double prob = (1.00/6.00);
	double ans = 0.00;
	ans += (prob * solve(i-1,max(p2-1,0LL),p3,p5));
	ans += (prob * solve(i-1,p2,max(p3-1,0LL),p5));
	ans += (prob * solve(i-1,max(p2-2,0LL),p3,p5));
	ans += (prob * solve(i-1,p2,p3,max(p5-1,0LL)));
	ans += (prob * solve(i-1,max(p2-1,0LL),max(p3-1,0LL),p5));
	ans += (prob * solve(i-1,p2,p3,p5));
	return dp[i][p2][p3][p5] = ans;
}
void solveQuestion(){
	int d;
	cin >> n >> d;
	power2 = 0,power3 = 0,power5 = 0;
	while(d % 2 == 0){
		d/=2;
		power2++;
	}
	while(d % 3 == 0){
		d/=3;
		power3++;
	}
	while(d % 5 == 0){
		d/=5;
		power5++;
	}
	if(d > 1){
		cout<<fixed<<setprecision(9)<<0.000000000<<'\n';
		return;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=power2;j++){
			for(int k=0;k<=power3;k++){
				for(int l=0;l<=power5;l++){
					dp[i][j][k][l] = -1.00;
				}
			}
		}
	}
	cout<<fixed<<setprecision(9)<<solve(n,power2,power3,power5)<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
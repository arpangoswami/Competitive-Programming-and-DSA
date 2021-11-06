#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
double dp[101][101][101];
double solve(int a,int b,int c){
	if(a == 100 || b == 100 || c == 100){
		return 0.00;
	}
	if(dp[a][b][c] > -0.9){
		return dp[a][b][c];
	}
	double sum = (double)(a + b + c);
	double prob1 = (double)a/sum,prob2 = (double)b/sum,prob3 = (double)c/sum;
	double ans = (prob1 * (solve(a+1,b,c) + 1.00)) + (prob2 * (solve(a,b+1,c) + 1.00)) + (prob3 * (solve(a,b,c+1) + 1.00));
	return dp[a][b][c] = ans;
}
void solveQuestion(){
	int a,b,c;
	cin >> a >> b >> c;
	memset(dp,-1,sizeof(dp));
	cout<<fixed<<setprecision(9)<<solve(a,b,c);
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
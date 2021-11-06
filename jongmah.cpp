#include <bits/stdc++.h>
#include <cstdlib>
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
const int MAX = 1e6+5;
//present sub:- next sub max value 2 + 2 -> max value 4
int dp[MAX-4][5][3];
int n,m;
vector<int> arr;
/*
10 5
2 2 4 4 3 1 1 2 3 2
100 10
7 4 5 5 10 10 5 8 5 7 4 5 4 6 8 8 2 6 3 3 10 7 10 8 6 2 7 3 9 7 7 2 4 5 2 4 9 5 10 1 10 5 10 4 1 3 4 2 6 9 9 9 10 6 2 5 6 1 8 10 4 10 3 4 10 5 5 4 10 4 5 3 7 10 2 7 3 6 9 6 1 6 5 5 4 6 6 4 4 1 5 1 6 6 6 8 8 6 2 6
*/
int solve(int idx,int present_sub,int next_sub){
	//i-2,i-1,i -> present_sub tuples  ; i-1,i,i+1 -> next_sub tuples, ; i,i+1,i+2 -> this we will calculate tuples
	if(idx > m){
		return 0;
	}
	if(dp[idx][present_sub][next_sub] != -1){
		return dp[idx][present_sub][next_sub];
	}
	int &ans = dp[idx][present_sub][next_sub];
	int curr_ele = arr[idx] - present_sub;
	int next_ele = arr[idx+1] - next_sub;
	int nextext_ele = arr[idx+2];
	int min_freq = min({curr_ele,next_ele,nextext_ele});
	ans = (curr_ele/3) + solve(idx+1,next_sub,0);
	if(min_freq >= 1){
		ans = max(ans,(curr_ele-1)/3 + 1 + solve(idx+1,next_sub+1,1));
	}
	if(min_freq >= 2){
		ans = max(ans,(curr_ele-2)/3 + 2 + solve(idx+1,next_sub+2,2));
	}
	return ans;
}
void solveQuestion(){
	arr.clear();
	cin >> n >> m;
	arr.resize(MAX);
	fill(arr.begin(),arr.end(),0);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr[x]++;
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=4;j++){
			for(int k=0;k<=2;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	cout<< solve(1,0,0) << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}

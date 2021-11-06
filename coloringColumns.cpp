#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[1001][1001];
vi colors;
vi leftCol;
vi rightCol;
/*
7
5 1 2 6 6 5 1 

5
3 3 1 2 1
*/
int solve(int i,int j){
	if(i > j){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int &ans = dp[i][j];
	int col1 = colors[i];
	int col2 = colors[j];
	if(col1 == col2){
		ans = 1 + solve(leftCol[i]+1,rightCol[j]-1);
	}else{
		ans = 1 + min(solve(leftCol[i]+1,j),solve(i,rightCol[j]-1));
	} 
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	colors.clear();
	leftCol.clear();
	rightCol.clear();
	colors.resize(n);
	leftCol.resize(n);
	rightCol.resize(n);
	for(int i=0;i<n;i++){
		cin >> colors[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	int col = colors[0],index = 0;
	for(int i=0;i<n;i++){
		if(colors[i] == col){
			rightCol[i] = index;
		}else{
			rightCol[i] = i;
			index = i;
			col = colors[i];
		}
	}
	col = colors[n-1],index = n-1;
	for(int i=n-1;i>=0;i--){
		if(colors[i] == col){
			leftCol[i] = index;
		}else{
			leftCol[i] = i;
			index = i;
			col = colors[i];
		}
	}
	// for(int x:leftCol){
	// 	cout<<x<<" ";
	// }
	// cout<<'\n';
	// for(int x:rightCol){
	// 	cout << x << " ";
	// }
	// cout<<"\n";
	cout << solve(0,n-1) << endl;
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
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 1e9;
vector<pii> arr;
int dp[1001][8];
int solve(int i,int mask){
	if(mask == 7){
		return 0;
	}
	if(i < 0){
		return inf;
	}
	if(dp[i][mask] != -1){
		return dp[i][mask];
	}
	return dp[i][mask] = min(arr[i].first + solve(i-1,mask | arr[i].second),solve(i-1,mask));
}
void solveQuestion(){
	int n;
	cin >> n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
		string s;
		cin >> s;
		arr[i].second = 0;
		for(char c:s){
			arr[i].second |= 1 << (c - 'a');
		}
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=7;j++){
			dp[i][j] = -1;
		}
	}
	int cost = solve(n-1,0);
	if(cost >= inf){
		cout << -1;
		return;
	}
	cout << cost;
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
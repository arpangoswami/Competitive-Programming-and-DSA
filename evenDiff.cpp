#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[100001];
int solve(int i,int n,string &s,vector<int> &arr){
	if(i == n){
		return dp[i] = 0;
	}
	if(dp[i] != -1){
		return dp[i];
	}
	if(s[i] == '1'){
		return dp[i] = min(1 + solve(i+1,n,s,arr),arr[i]);
	}
	return dp[i] = solve(i+1,n,s,arr);
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> arr(n);
	if(s[n-1] == '0'){
		arr[n-1] = 1;
	}
	for(int i=n-2;i>=0;i--){
		arr[i] = arr[i+1];
		if(s[i] == '0'){
			arr[i]++;
		}
	}
	for(int i=0;i<=n;i++){
		dp[i] = -1;
	}
	cout<<solve(0,n,s,arr)<<'\n';
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
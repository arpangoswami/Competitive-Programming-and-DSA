#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dp[200001][2][2];
int n;
string s;
int solve(int i,int last1,int last2,int cnt1,int cnt2){
	if(i == n){
		if(cnt1 == n/2 && cnt2 == n/2){
			return 1;
		}
		return 0;
	}
	if(dp[i][last1][last2] != -1){
		return dp[i][last1][last2];
	}
	int right1 = i-cnt1,right2 = i-cnt2;
	int ans = 0;
	if(s[i] == '1'){
		//both left
		ans = solve(i+1,0,0,cnt1+1,cnt2+1);
		//both right
		if(cnt1 > right1 && cnt2 > right2){
			ans = ans | solve(i+1,1,1,cnt1,cnt2);
		}
	}else{
		//l1 left r1 right
		if(cnt2 > right2){
			ans = solve(i+1,0,1,cnt1+1,cnt2);
		}
		//l1 right r1 left
		if(cnt1 > right1){
			ans = ans | solve(i+1,1,0,cnt1,cnt2 + 1);
		}
	}
	return dp[i][last1][last2] = ans;
}
void solveQuestion(){	
	cin >> n >> s;
	if(s[0] == '0'){
		cout<<"NO"<<'\n';
		return;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	int ans =  solve(1,0,0,1,1);
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
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
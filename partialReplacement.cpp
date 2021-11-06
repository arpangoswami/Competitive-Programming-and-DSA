#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int ans;
int k;
int dp[51][51];
string s;
int solve(int i,int lastX){
	if(i < 0){
		return 0;
	}
	//cout << "i: "<<i<<" s[i]: "<<s[i]<<'\n';
	if(dp[i][lastX] != -1){
		return dp[i][lastX];
	}
	int &ans = dp[i][lastX];
	if(s[i] == '*'){
		int add = 1;
		if((lastX - i) > k){
			add = 1e9;
		}
		return ans = min(solve(i-1,lastX),add + solve(i-1,i));
	}else if(s[i] == '.'){
		return ans = solve(i-1,lastX);
	}else if(s[i] == 'x'){
		//cout << "lastX: "<<lastX<<" i: "<<i<<'\n';
		if((lastX - i) > k){
			
			return ans = 1e9;
		}
		return ans = solve(i-1,i);
	}
}
void solveQuestion(){
	int n;
	cin >> n >> k >> s;
	ans = 0;
	int index = -1;
	for(int i=n-1;i>=0;i--){
		if(s[i] == '*'){
			s[i] = 'x';
			ans++;
			index = i;
			break;
		}
	}
	for(char &c:s){
		if(c == '*'){
			c = 'x';
			ans++;
			break;
		}
	}
	//cout << "s: "<<s<<'\n';
	if(ans == 0 || ans == 1){
		cout << ans << '\n';
		return;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	//cout << solve(index,index) << '\n';
	cout << ans + solve(index,index) << '\n';
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
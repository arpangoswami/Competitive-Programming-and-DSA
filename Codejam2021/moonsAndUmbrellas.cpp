#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int x,y,n;
string s;
int dp[1001][2];
const int inf = 1e5+1;
//0 -> last character C, 1->last character J
int solve(int i,int last){
	if(i == n){
		return 0;
	}
	if(i == 0){
		if(s[i] == '?'){
			return min(solve(i+1,0),solve(i+1,1));
		}else{
			if(s[i] == 'C'){
				return solve(i+1,0);
			}else{
				return solve(i+1,1);
			}
		}
	}
	if(dp[i][last] != -inf){
		return dp[i][last];
	}
	int &ans = dp[i][last];
	if(s[i] == '?'){
		if(last == 0){
			ans = min(solve(i+1,0),solve(i+1,1) + x);
		}else{
			ans = min(solve(i+1,1),solve(i+1,0) + y);
		}
	}else if(s[i] == 'C'){
		if(last == 0){
			ans = solve(i+1,0);
		}else{
			ans = solve(i+1,0) + y;
		}
	}else{
		if(last == 0){
			ans = solve(i+1,1) + x;
		}else{
			ans = solve(i+1,1);
		}
	}
	return ans;
}
void solveQ(){	
	cin >> x >> y >> s;
	n = s.size();
	if(x > 0 && y > 0){
		int ans = 0;
		int n = s.size();
		char prev = '$';
		for(int i=0;i<n;i++){
			if(s[i] == '?' || s[i] == prev){
				continue;
			}else if(s[i] != prev){
				if(prev == '$'){
					prev = s[i];
				}else if(s[i] == 'C'){
					ans += y;
					prev = 'C';
				}else if(s[i] == 'J'){
					ans += x;
					prev = 'J';
				}
			}
		}
		cout << ans << '\n';
	}else{
		for(int i=0;i<=n;i++){
			for(int j=0;j<=1;j++){
				dp[i][j] = -inf;
			}
		}
		cout << solve(0,-1) << '\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}